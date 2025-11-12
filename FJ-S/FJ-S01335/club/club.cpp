#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
struct N
{
	int val,ks,rd;
	int id,bm;
} a[300005];
int o[100005],t[100005],r[100005];
int num[4];
bool b[300005];
bool cmp(N ax,N bx)
{
	if(ax.ks==bx.ks) return ax.val>bx.val;
	return ax.ks-ax.val<bx.ks-bx.val;
}
bool cmp1(N ax,N bx)
{
	return ax.val>bx.val;
}
bool cmp2(N ax,N bx)
{
	return ax.ks+ax.val<bx.ks+bx.val;
}
bool cmp3(N ax,N bx)
{
	return ax.ks-bx.val<bx.ks-ax.val;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	/*
	1
	2
	10 9 8
	4 0 0
	*/
	while(T--)
	{
//		if(T>0) continue;
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[3*(i-1)+1].val;
			o[i]=a[3*(i-1)+1].val;
			a[3*(i-1)+1].id=1;
			a[3*(i-1)+1].bm=i;
			cin>>a[3*(i-1)+2].val;
			t[i]=a[3*(i-1)+1].val;
			a[3*(i-1)+2].id=2;
			a[3*(i-1)+2].bm=i;
			cin>>a[3*(i-1)+3].val;
			r[i]=a[3*(i-1)+1].val;
			a[3*(i-1)+3].id=3;
			a[3*(i-1)+3].bm=i;
		}
		/*
		1
		4
		1 9 9
		1 7 9
		1 8 9
		1 1 1
		*/
		for(int i=1; i<=3; i++)
		{
			int tt=0;
			for(int j=1; j<=n; j++)
			{
				tt+=a[3*(j-1)+i].val;
			}
			for(int j=1; j<=n; j++)
			{
				a[3*(j-1)+i].ks+=a[3*(j-1)+1].val+a[3*(j-1)+2].val+a[3*(j-1)+3].val-a[3*(j-1)+i].val;
			}
		}
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		int anss=0;
		sort(a+1,a+3*n+1,cmp);
		for(int i=1; i<=3*n; i++)
		{
//			cout<<a[i].id<<" "<<a[i].bm<<" "<<a[i].val<<" "<<a[i].ks<<"\n";
			if(!b[a[i].bm])
			{
				if(num[a[i].id]+1<=n/2)
				{
					num[a[i].id]++;
//					cout<<"Y\n";
					ans+=a[i].val;
					b[a[i].bm]=1;
				}
			}
		}
		anss=max(anss,ans);
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		ans=0;
		sort(a+1,a+3*n+1,cmp1);
		for(int i=1; i<=3*n; i++)
		{
//			cout<<a[i].id<<" "<<a[i].bm<<" "<<a[i].val<<" "<<a[i].ks<<"\n";
			if(!b[a[i].bm])
			{
				if(num[a[i].id]+1<=n/2)
				{
					num[a[i].id]++;
//					cout<<"Y\n";
					ans+=a[i].val;
					b[a[i].bm]=1;
				}
			}
		}
		anss=max(anss,ans);
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		ans=0;
		sort(a+1,a+3*n+1,cmp2);
		for(int i=1; i<=3*n; i++)
		{
//			cout<<a[i].id<<" "<<a[i].bm<<" "<<a[i].val<<" "<<a[i].ks<<"\n";
			if(!b[a[i].bm])
			{
				if(num[a[i].id]+1<=n/2)
				{
					num[a[i].id]++;
//					cout<<"Y\n";
					ans+=a[i].val;
					b[a[i].bm]=1;
				}
			}
		}
		anss=max(anss,ans);
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		ans=0;
		sort(a+1,a+3*n+1,cmp3);
		for(int i=1; i<=3*n; i++)
		{
//			cout<<a[i].id<<" "<<a[i].bm<<" "<<a[i].val<<" "<<a[i].ks<<"\n";
			if(!b[a[i].bm])
			{
				if(num[a[i].id]+1<=n/2)
				{
					num[a[i].id]++;
//					cout<<"Y\n";
					ans+=a[i].val;
					b[a[i].bm]=1;
				}
			}
		}
		anss=max(anss,ans);
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		ans=0;
//		sort(a+1,a+3*n+1,cmp4);
		for(int i=1; i<=3*n; i++)
		{
//			cout<<a[i].id<<" "<<a[i].bm<<" "<<a[i].val<<" "<<a[i].ks<<"\n";
			if(!b[a[i].bm])
			{
				if(num[a[i].id]+1<=n/2)
				{
					num[a[i].id]++;
//					cout<<"Y\n";
					ans+=a[i].val;
					b[a[i].bm]=1;
				}
			}
		}
		anss=max(anss,ans);
		// f[1/2/3][i] = max (f[] )
//		cout<<num[1]<<" "<<num[2]<<" "<<num[3]<<"\n";
		cout<<anss<<"\n";
	}
}
/*
1
6
9 9 15
6 6 1
9 12 7
7 16 12
11 18 18
1 2 17
1
4
4 2 1
3 2 4
5 3 4
3 5 1
5+5+4+4
1
5
3 9 2
3 8 9
2 5 10
3 1 2
2 2 2
*/
