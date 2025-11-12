#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,s=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int a1,a2,a3;
		for(int j=1;j<=n;j++)
		{
			cin>>a1>>a2>>a3;
		}
		s=0;
		for(int j=1;j<=n;j++)
		{
			if(a1>a2&&a1>a3)
			{
				s=s+a1;
			}
			if(a1<a2&&a2>a3)
			{
				s=s+a2;
			}
			if(a1<a3&&a2<a3)
			{
				s=s+a3;
			}
		}
		cout<<s;
	}
}
