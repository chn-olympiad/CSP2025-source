#include<bits/stdc++.h>
using namespace std;
long long n,T,ans=0,l[5];
priority_queue <long long> q[5];
struct node
{
	long long v,n;
}a[100010][5];
bool cmp(node x,node y)
{
	if(x.v!=y.v) return x.v>y.v;
	return x.n<y.n;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("in.in","r",stdin);
//	freopen("zhengjie.out","w",stdout);
	cin>>T;
//	cout<<T<<endl;
	while(T--)
	{
		cin>>n;
//		cout<<n<<endl;
		ans=0;	
		for(long long i=1;i<=3;i++) 
		{
			l[i]=0;
			while(!q[i].empty()) q[i].pop();
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) a[i][j].n=a[i][j].v=0;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a[i][1].v,&a[i][2].v,&a[i][3].v);
			a[i][1].n=1,a[i][2].n=2,a[i][3].n=3,a[i][4].v=0,a[i][4].n=4;
			sort(a[i]+1,a[i]+3+1,cmp);
		}
//		cout<<endl;
//		for(long long i=1;i<=n;i++) cout<<a[i][1].n<<' '<<a[i][2].n<<' '<<a[i][3].n<<endl;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=3;j++)
			{
				long long go=a[i][j].n;
//				if(j==3) return 114514;
				if(l[go]>=n/2)
				{
					long long x=q[go].top();
//					cout<<"ch "<<x<<' '<<a[i][j].v<<endl;
					if(x>a[i][j+1].v-a[i][j].v)
					{
						ans=ans+a[i][j].v+x;
						q[go].pop();
						q[go].push(-1*(a[i][j].v-a[i][j+1].v));
//						cout<<"sdfaadsfasf\n";
						break;
					}
//					else
//					{
//						ans+=a[i][j+1].v;
//						break;
//					}
				}
				else
				{
//					cout<<i<<' '<<go<<endl;
					l[go]++;
					ans+=a[i][j].v;
					q[go].push(-1*(a[i][j].v-a[i][j+1].v));
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
1
2
83 37 0
90 59 0

*/
