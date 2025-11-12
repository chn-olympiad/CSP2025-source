#include<bits/stdc++.h>
using namespace std;
const int N=10e5+5;
long long t,n,s;
struct student
{
	long long k,i,j,d;
}a[N];
bool cmp(student a,student b)
{
	return a.d>b.d;
}
int fi[N],fj[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=3*n;i+=3)
		{
			cin>>a[i].k>>a[i+1].k>>a[i+2].k;
			a[i].i=i;
			a[i].j=1;
			a[i].d=a[i].k-a[i+1].k-a[i+2].k;
			a[i+1].i=i;
			a[i+1].j=2;
			a[i+1].d=a[i+1].k-a[i].k-a[i+2].k;
			a[i+2].i=i;
			a[i+2].j=3;
			a[i+2].d=a[i+2].k-a[i+1].k-a[i].k;
			//cout<<i<<":"<<a[i].d<<" "<<a[i+1].d<<" "<<a[i+2].d<<"\n";
		}
		sort(a+1,a+3*n+1,cmp);
		for(int i=1;i<=3*n;i++)
		{
			//cout<<a[i].k<<":"<<fi[a[i].i]<<" "<<fj[a[i].j]<<"\n";
			if(a[i].k==a[i+1].k&&fj[a[i].j]>fj[a[i].j+1])
				swap(a[i],a[i+1]);
			
			if(fi[a[i].i]==0&&fj[a[i].j]<=n/2-1)
			{
				s+=a[i].k;
				fi[a[i].i]=1;fj[a[i].j]++;
			}
		}
		cout<<s<<"\n";
		for(int i=1;i<=3*n;i++)fi[i]=0;
		fj[1]=fj[2]=fj[3]=0;
		memset(a,0,sizeof(a));
		s=0;
	}
	return 0;
}
