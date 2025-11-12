#include<bits/stdc++.h>
using namespace std;
const int N=5001,md=998244353;
//int count(int s,int e,int no,int a[])
//{	int res=0;
//	for(int i=s;i<=e;i++)
//	{	if(i==no)
//			continue;
//		res+=a[i];
//	}
//	return res;
//}
//int MAX(int s,int e,int no,int a[])
//{	int mx=-1;
//	for(int i=s;i<=e;i++)
//	{	if(i==no)
//			continue;
//		mx=max(a[i],mx);
//	}
//	return mx;
//}
long long dg(int x)
{	if(x==1)
		return 1;
	return x*dg(x-1)%md;
}
void solve()
{	int n,a[N],cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//for(int i=1;i<=n-3;i++)
	//	for(int j=i+3;j		<=n;j++)
	//		for(int k=i;k<=j;k++)
	//		{	int tot=count(i,j,k,a),mmax=MAX(i,j,k,a);
	//			if(tot*2>mmax)
	//				cnt++;
	//		}
	//cout<<cnt<<"\n";
	cout<<dg(n/2+1)%md<<"\n";
}
int main()
{	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}
//DeBruyne rp++
