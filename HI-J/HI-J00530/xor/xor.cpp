#include<bits/stdc++.h>
using namespace std;
string awa(int a)
{
	string omo="";
	while(a)
	{
		omo+=a%2;
		a=a/2;
	}
	return omo;
} 
long long s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	string b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=awa(a[i]);
		if(a[i]==k)
		{
			s++;
		}
	}
	int pwp=k;
	string kk;
	while(pwp)
	{
		kk+=pwp%2;
		pwp/=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j-1;k++)
			{
				string sss;
				for(int l=0;l<=max(b[i].size(),b[i+1].size())-1;i++)
				{
					if(b[i][l]!=b[i+1][l])
					{
						sss[l]='1';
					}else
					{
						sss[l]='0';
					}
				}
				if(sss==kk)
				{
					s++;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
