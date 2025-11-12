#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans,s[4],sp,n,t;
priority_queue<int,vector<int>,greater<int>> q[4];
void work()
{
	cin>>n;ans=0;
	while(!q[1].empty()) 
	 q[1].pop();
	while(!q[2].empty()) 
	 q[2].pop();
	while(!q[3].empty()) 
	 q[3].pop();
	s[1]=s[2]=s[3]=0;
	for(int i=1,x,y,z;i<=n;i++)
	{
		cin>>x>>y>>z;
		if(x>y&&x>z)
		{
			ans+=x;
			q[1].push(x-max(y,z));s[1]++;
		}
		else if(y>z)
		{
			ans+=y;
			q[2].push(y-max(x,z));s[2]++;
		}
		else
		{
			ans+=z;
			q[3].push(z-max(x,y));s[3]++;
		}
	}
	if(s[1]>n/2) sp=1;
	if(s[2]>n/2) sp=2;
	if(s[3]>n/2) sp=3;
	for(int i=s[sp];i>n/2;i--)
	{
		ans-=q[sp].top();
		q[sp].pop();
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--) 
	work();
	return 0;
} 
