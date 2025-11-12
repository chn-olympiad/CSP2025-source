#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=110;
ll a[N],b[N];
ll n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n*m);
	ll tot=n*m;
	for(int j=1;j<=m;j++)
		if(j&1)
			for(int i=1;i<=n;i++)
				if(a[1]==b[tot])
				{
					cout<<j<<" "<<i<<"\n";
					return 0;
				}
				else tot--;
		else
			for(int i=n;i>=1;i--)
				if(a[1]==b[tot])
				{
					cout<<j<<" "<<i<<"\n";
					return 0;
				}
				else tot--;
	return 0;
}
/*
//freopen
//freopen
froepen
freoepn
#include<bits\stdc++.h> 
x0 y0 x1 y1
signed main() 
*/
