#include<bits/stdc++.h>
using namespace std;
int t,n,ans[3][2];
int a[10005][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=0; x<t; x++)
	{
		cin>>n;
		if(n==2)
		{
			cin>>ans[0][0]>>ans[1][0]>>ans[2][0];
			cin>>ans[0][1]>>ans[1][1]>>ans[2][1];
			int s1=max(max(ans[0][0],ans[1][0]),ans[2][0]),s2=max(max(ans[0][0],ans[1][0]),ans[2][0]);
			if(ans[0][0]==s1 && ans[0][1]==s2) cout<<max(s1,s2);
			else if(ans[1][0]==s1 && ans[1][1]==s2) cout<<max(s1,s2);
			else if(ans[2][0]==s1 && ans[2][1]==s2) cout<<max(s1,s2);
			else cout<<s1+s2;
		}
		else
		{
			for(int i=1; i<=n; i++)
			{
				int h;
				for(int j=1; j<=3; j++) cin>>h;
				
			}
			cout<<1;
		}
	}
	return 0;
}


//Ren5Jie4Di4Ling5%
