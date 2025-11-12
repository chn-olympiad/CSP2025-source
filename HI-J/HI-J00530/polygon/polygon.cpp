#include<bits/stdc++.h>
using namespace std;
int sss=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[n+1];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			int s=0,ss=0;
			for(int l=j;l<=j+i-1;l++)
			{
				s=max(s,l);
			}
			for(int k=j;k<=j+i-1;k++)
			{
				ss+=a[k];
			}
			if(ss>s*2) sss++;
		}
	}
	cout<<sss%998244353;
	return 0;
}
