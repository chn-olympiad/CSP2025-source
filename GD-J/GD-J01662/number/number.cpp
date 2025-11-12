#include<bits/stdc++.h>
using namespace std;
using ll=long long;

char c[1001000];
ll a[1001000],j=1;

bool cmp(ll a,ll b){return a>b;}

void solve()
{
	cin>>c;
	for(ll i=0;i<strlen(c);i++)
	{
		ll x=int(c[i]);
		if(x>=48 && x<=57)
		{
			a[j]=x-48;
			j++;
		}
	}
	sort(a+1,a+j,cmp);
	for(ll i=1;i<j;i++) cout<<a[i];
	return;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
