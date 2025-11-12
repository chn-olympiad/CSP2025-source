#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int s[100005][4];
int fun(int a1,int a2,int a3,int b1,int b2,int b3)
{
	int m=a1+b2;
	m=max(m,a1+b3);
	m=max(m,a2+b1);
	m=max(m,a2+b3);
	m=max(m,a3+b1);
	return max(m,a3+b2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
		for(int i=1;i<n;i++)
		{
			if(i%2!=0) ans=ans+fun(s[i][1],s[i][2],s[i][3],s[i+1][1],s[i+1][2],s[i+1][3]);
		}	
		cout<<ans<<endl;
	}
	return 0;
}
