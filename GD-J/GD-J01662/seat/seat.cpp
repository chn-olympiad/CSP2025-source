#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,x,a[100100],ansx,ansy,k;

bool cmp(ll a,ll b){return a>b;}

void solve()
{
	cin>>n>>m;
	cin>>a[1];
	x=a[1];
	for(ll i=2;i<=m*n;i++) cin>>a[i];
	sort(a+1,a+(n*m)+1,cmp);
	for(ll i=1;i<=m*n;i++)
	{
		if(a[i]==x)
		{
			k=i;
			break;
		}
	}
	if(n==1)
	{
		cout<<1<<" "<<k;
		return;
	}
	if(m==1)
	{
		cout<<k<<" "<<1;
		return;
	}
	if(n==1 && m==1)
	{
		cout<<1<<" "<<1;
		return;
	}
	
	ansx=ll(ceil(k*1.0/n));
	if(ansx%2==1)
	{
		ansy=k%m;
		if(ansy==0) ansy=m;
	}
	else
	{
		ansy=k%m;
		ansy++;
	}
	cout<<ansx<<" "<<ansy;
	return; 
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
