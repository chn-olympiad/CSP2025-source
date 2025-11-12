#include<bits/stdc++.h>
using namespace std;
namespace chole
{
	#define int long long
	int T;
	int n;
	struct node
	{
		int x,y,z;
		int c,m;
	}a[100010];
	int A[100010];
	int B[100010];
	int C[100010];
	int q[100010];
	signed main()
	{
		cin>>T;
		while(T--)
		{
			memset(A,0,sizeof(A));
			memset(B,0,sizeof(B));
			memset(C,0,sizeof(C));
			memset(q,0,sizeof(q));
			int ans=0,cnta=0,cntb=0,cntc=0;
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i].x>>a[i].y>>a[i].z;
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
				{
					a[i].m=a[i].x;
					A[++cnta]=i;
				}
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
				{
					a[i].m=a[i].y;
					B[++cntb]=i;
				}
				if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
				{
					a[i].m=a[i].z;
					C[++cntc]=i;
				}
				ans+=a[i].m;
				if(a[i].x>=a[i].y&&a[i].x<=a[i].z||a[i].x<=a[i].y&&a[i].x>=a[i].z)
				{
					a[i].c=a[i].m-a[i].x;
				}
				if(a[i].y>=a[i].x&&a[i].y<=a[i].z||a[i].y<=a[i].x&&a[i].y>=a[i].z)
				{
					a[i].c=a[i].m-a[i].y;
				}
				if(a[i].z>=a[i].x&&a[i].z<=a[i].y||a[i].z<=a[i].x&&a[i].z>=a[i].y)
				{
					a[i].c=a[i].m-a[i].z;
				}
			}
//			cout<<ans<<endl;
//			for(int i=1;i<=n;i++)
//			{
//				cout<<a[i].m<<" "<<a[i].c<<endl;
//			}
			if(cnta>n/2)
			{
				int cntq=0;
				for(int i=1;i<=cnta;i++)
				{
					q[i]=a[A[i]].c;
				}
				sort(q+1,q+cnta+1);
				for(int i=1;i<=cnta-n/2;i++)
				{
					ans-=q[i];
				}
			}
			if(cntb>n/2)
			{
				int cntq=0;
				for(int i=1;i<=cntb;i++)
				{
					q[i]=a[B[i]].c;
				}
				sort(q+1,q+cntb+1);
				for(int i=1;i<=cntb-n/2;i++)
				{
					ans-=q[i];
				}
			}
			if(cntc>n/2)
			{
				for(int i=1;i<=cntc;i++)
				{
					q[i]=a[C[i]].c;
				}
//				cout<<q[1]<<endl;
//				for(int i=1;i<=cntc;i++)
//				{
//					cout<<q[i]<<" ";
//				}
				sort(q+1,q+cntc+1);
				for(int i=1;i<=cntc-n/2;i++)
				{
					ans-=q[i];
				}
			}
			cout<<ans<<endl;
//			cout<<"------------"<<endl;
		}
		return 0;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return chole::main(); 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
