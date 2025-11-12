#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100005],b[100005],c[100005];
bool cmp1(node x,node y)
{
	return x.x<y.x;
}
int ma=0,n;
void dfs(int i,int x,int y,int z,int s)
{
	if(i==n+1)
	{
		ma=max(ma,s);
		return;
	}
	if(x<n/2)
		dfs(i+1,x+1,y,z,a[i].x+s);
	if(y<n/2)
		dfs(i+1,x,y+1,z,a[i].y+s);
	if(z<n/2)
		dfs(i+1,x,y,z+1,a[i].z+s);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int maa=0,mab=0,mac=0,sa1=0,sb1=0,sc1=0,sa2=0,sb2=0,sc2=0;
		ma=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z,maa=max(maa,a[i].x),mab=max(mab,a[i].y),mac=max(mac,a[i].z);
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
				sa1++,sa2+=a[i].x;
			if(a[i].y>a[i].x&&a[i].y>=a[i].z)
				sb1++,sb2+=a[i].y;
			if(a[i].z>a[i].x&&a[i].z>a[i].y)
				sc1++,sc2+=a[i].z;
		}
		if(mab==0&&mac==0)
		{
			int s=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=n;i>n/2;i--)
				s+=a[i].x;
			cout<<s<<endl;
			continue;
		}
		if(mac==0)
		{
			priority_queue<int>q;
			sort(a+1,a+n+1,cmp1);
			int s=0;
			for(int i=n;i>n/2;i--)
			{
				s+=a[i].x;
				q.push(-a[i].x+a[i].y);
			}
			for(int i=n/2;i>=1;i--)
			{
				s+=a[i].y;
				int x=-q.top();
				//cout<<a[i].x<<" "<<a[i].y<<x<<endl;
				if(a[i].x-a[i].y>x)
				{
					s=s-x+a[i].x-a[i].y;
					q.pop();
					q.push(-a[i].x+a[i].y);
				}
			}
			cout<<s<<endl;
			continue;
		}
		if(sa1<=n/2&&sb1<=n/2&&sc1<=n/2)
		{
			cout<<sa2+sb2+sc2<<endl;
			continue;
		}
		if(n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<ma<<endl;
			continue;
		}
		/*priority_queue<pair<int,pair<int,int>>>q2;
		sort(a+1,a+n+1,cmp1);
		int s=0;
		for(int i=n;i>n/2;i--)
		{
			//cout<<a[i].x<<" ";
			s+=a[i].x;
			b[i]=1;
			q2.push({-a[i].x+a[i].y,{i,1}});
		}
		for(int i=n/2;i>=1;i--)
		{
			//cout<<a[i].x<<" ";
			b[i]=2;
			s+=a[i].y;
			auto x=q2.top();
			if(a[i].x-a[i].y>-x.first)
			{
				s=s+x.first+a[i].x-a[i].y;
				b[i]=1;
				b[x.second.first]=2;
				q2.pop();
				q2.push({-a[i].x+a[i].y,{i,2}});
			}
		}
		while(!q2.empty())
			q2.pop();
		for(int i=1;i<=n;i++)
		{
			if(b[i]==2)
				q2.push({-a[i].y+a[i].z,{i,1}});//,cout<<-a[i].x+a[i].z<<" ";
			else
				q2.push({-a[i].x+a[i].z,{i,2}});//,cout<<-a[i].y+a[i].z<<" ";
		}
		for(int i=1;i<=n/2;i++)
		{
			auto x=q2.top();
			cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
			if(x.first>0)
			{
				s=s+x.first;
				q2.pop();
			}
			else
				break;
		}
		cout<<s<<endl;*/
		int s=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
			b[i]={a[i].x-a[i].y,i,0},s+=a[i].x;
		sort(b+1,b+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(i<=n/2)
				c[i]={a[b[i].y].y-a[b[i].y].z,b[i].y,0},s-=b[i].x;
			else
				c[i]={a[b[i].y].x-a[b[i].y].z,b[i].y,0};			
		}
		sort(c+1,c+n+1,cmp1);
		for(int i=1;i<=n/2;i++)
			if(c[i].x<0)
				s-=c[i].x;
		cout<<s<<endl;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	return 0;
}
