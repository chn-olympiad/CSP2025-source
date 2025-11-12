#include<bits/stdc++.h>
using namespace std;
long long s,n,m=1,cnt,sum,maxn=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while(s)
	{
		n=s%10;
		if(n==0) cnt++;
		sum+=n*m;
		s/=10;
		m*=10;
	}
	maxn=max(s,maxn);
	maxn=max(sum,s);
	if(cnt==0) cout<<maxn;
	if(cnt==1) cout<<maxn<<" "<<0;
	if(cnt==2) cout<<maxn<<" "<<0<<" "<<0;
	if(cnt==3) cout<<maxn<<" "<<0<<" "<<0<<" "<<0;
	if(cnt==4) cout<<maxn<<" "<<0<<" "<<0<<" "<<0<<" "<<0;
	if(cnt==5) cout<<maxn<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0;
	if(cnt==6) cout<<maxn<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0;
	return 0;
}
