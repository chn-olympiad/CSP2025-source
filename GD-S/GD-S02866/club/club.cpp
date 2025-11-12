#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t,ans,f[N][4],l1,l2,l3;
struct node{
	int m1,m2;
}a[N]; 
priority_queue<int> q1,q2,q3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0,l1=0,l2=0,l3=0;
		cin>>n;
		memset(a,0,sizeof(a));
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		for(int i=1;i<=n;i++)
		{
			cin>>f[i][1]>>f[i][2]>>f[i][3];
			for(int j=1;j<=3;j++)
				if(f[i][j]>=f[i][a[i].m1]) a[i].m2=a[i].m1,a[i].m1=j;
				else if(f[i][j]>=f[i][a[i].m2]) a[i].m2=j;
		}
//		for(int i=1;i<=n;i++) cout<<a[i].m1<<" "<<a[i].m2<<"\n";
		for(int i=1;i<=n;i++)
		{
			if(a[i].m1==1)
			{
				if(l1==n/2)
				{
//					cout<<"1\n";
					if(q1.top()>f[i][a[i].m2]-f[i][a[i].m1]) 
					{
						ans+=q1.top()+f[i][a[i].m1];
						q1.pop();
						q1.push(f[i][a[i].m2]-f[i][a[i].m1]);
					}
					else ans+=f[i][a[i].m2];
				}
				else l1++,ans+=f[i][a[i].m1],q1.push(f[i][a[i].m2]-f[i][a[i].m1]);
			}
			if(a[i].m1==2)
			{
				if(l2==n/2)
				{
//					cout<<"2\n";
					if(q2.top()>f[i][a[i].m2]-f[i][a[i].m1]) 
					{
						ans+=q2.top()+f[i][a[i].m1];
						q2.pop();
						q2.push(f[i][a[i].m2]-f[i][a[i].m1]);
					}
					else ans+=f[i][a[i].m2];
				}
				else l2++,ans+=f[i][a[i].m1],q2.push(f[i][a[i].m2]-f[i][a[i].m1]);
			}
			if(a[i].m1==3)
			{
				if(l3==n/2)
				{
					if(q3.top()>f[i][a[i].m2]-f[i][a[i].m1]) 
					{
						ans+=q3.top()+f[i][a[i].m1];
						q3.pop();
						q3.push(f[i][a[i].m2]-f[i][a[i].m1]);
					}
					else ans+=f[i][a[i].m2];
				}
				else l3++,ans+=f[i][a[i].m1],q3.push(f[i][a[i].m2]-f[i][a[i].m1]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
