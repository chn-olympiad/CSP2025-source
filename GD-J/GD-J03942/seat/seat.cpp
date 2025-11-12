#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k[N],now;
int cmp(int a,int b){return a>b;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>k[i-1];
		if(i==1) now=k[i-1];
	}
	sort(k,k+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(k[i-1]==now)
		{
			int ans;
			if(i%n==0) ans=i/n;
			else ans=i/n+1;
			int ans2=(ans%2==0? n-(i-1)%n : (i-1)%n+1);
			cout<<ans<<' '<<ans2<<endl;
			return 0;
		}
	}
	return 0;
}//T2 ´óÔ¼ 100pts 
