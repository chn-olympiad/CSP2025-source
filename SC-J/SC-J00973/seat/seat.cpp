#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e2+6;
struct good{
	ll a,i;
}e[N];
bool great(good a,good b){
	return a.a>b.a;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>e[i].a,e[i].i=i;
	sort(e+1,e+1+n*m,great);
	ll k;
	for(int i=1;i<=n*m;i++)
		if(e[i].i==1)
			k=i;
	ll lie,h;
	if(k%n==0)
		lie=k/n,h=n;
	else
		lie=k/n+1,h=k-(lie-1)*n;
	if(lie%2==0)
		h=n-h+1;
	cout<<lie<<" "<<h;
	return 0;
}