#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool p[100050];
bool check(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(p[i]) return false;
	}
	return true;
}
void pp(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		p[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n+10],s[n+10],f[n+10][n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
  		{
			  if(l==r) f[l][r]=a[l];
			  else f[l][r]=f[l][r-1]^a[r];
		}
	}
	long long sum=0;
	for(int j=1;j<=n;j++)
	{
		for(int l=1;l+j-1<=n;l++)
		{
			if(f[l][l+j-1]==k&&check(l,l+j-1)) 
			{
			sum++;pp(l,l+j-1);
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
