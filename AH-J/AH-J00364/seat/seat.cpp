#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long cmp(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) cin>>a[i];
	long long bj=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	long long wz,ls,hs;
	for(long long i=1;i<=n*m;i++) if(a[i]==bj) wz=i;
	if(wz%n==0) ls=wz/n;
	else ls=wz/n+1;
	if(ls%2==1) 
	{
		if(wz%n==0) hs=n;
		else hs=wz%n;
	}
	else 
	{
		if(wz%n==0) hs=1;
		else hs=n-wz%n+1;
	}
	cout<<ls<<" "<<hs;
    return 0;
}
//rp++
