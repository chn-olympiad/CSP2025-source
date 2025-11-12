#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[10005];
ll k;
ll ln,rw;
bool cmp(ll a,ll b) { return a>b; }
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) 
		cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++) 
		if(a[i]==k) {
			rw=i;
			break;
		}
	ln=rw/n;
	rw%=n;
	if(rw==0) {
		ln--;
		rw+=n;
	}
	cout<<ln+1<<" ";
	if(ln%2==0) 
		cout<<rw<<endl;
	else 
		cout<<n-rw+1<<endl;
	return 0;
}
