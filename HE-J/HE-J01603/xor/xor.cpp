#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N],ans;
bool b[N];
bool c(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(b[i]==true) return true;
	}
	return false;
}
void cc(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		b[i]=true;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool bo=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) bo=false;
		if(a[i]==k)
		{
			ans++;
			b[i]=true;
		}
		s[i]=s[i-1]^a[i];
	}
	if(n==1&&k==0&&bo==1){
		cout<<0;
		return 0;
	}else if(n==2&&k==0&&bo==1){
		cout<<1;
		return 0;
	}
	if(k==0&&bo==1)
	{
		cout<<n/2;
		return 0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l;
			if(s[j]^s[i-1]==k&&c(i,j)==false)
			{
				ans++;
				cc(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
