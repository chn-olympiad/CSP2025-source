#include<bits/stdc++.h>
using namespace std;
int t;
long n,k1,k2,k3;
struct Node{
	long m;
	long num;
	int club;
}a[400000];
//Node a[400000];
bool b[200000];
long long ans=0;

bool cmp(Node x,Node y)
{
	return x.m>y.m;
}
int main()
{
	freopen("club.in.txt","r",stdin);
	freopen("club.out.txt","w",stdout);
	cin>>t;
	while(t--)
	{
		k1=0,k2=0,k3=0;
		ans=0;
		cin>>n;
		for(long i=1;i<=n;i++)
		{
			b[i]=0;
			cin>>a[i*3-2].m>>a[i*3-1].m>>a[i*3].m;
			a[i*3-2].num=i,a[i*3-2].club=1;
			a[i*3-1].num=i,a[i*3-1].club=2;
			a[i*3].num=i,a[i*3].club=3;
		}
		sort(a+1,a+3*n+1,cmp);
		for(long i=1;i<=n;i++)
		{
			long k;
			if(a[i].club==1)k=k1;
			if(a[i].club==2)k=k2;
			if(a[i].club==3)k=k3;
			if(b[a[i].num]==0&&k<n/2)
			{
				ans+=a[i].m;
				b[a[i].num]=1;
				if(a[i].club==1)k1++;
				if(a[i].club==2)k2++;
				if(a[i].club==3)k3++;
			}
		}
		cout<<ans;
	}
	return 0;
}
