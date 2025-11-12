#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[105],w,d,mpm,c,r,kl;
bool cmp(const ll &p,const ll &q){return p>q;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	d=n*m;
	for(ll i=1;i<=d;i++)cin>>a[i];
	w=a[1];
	sort(a+1,a+d+1,cmp);
	for(ll i=1;i<=d;i++){
		if(a[i]==w){
			mpm=i;
			break;
		}
	}
	c=(mpm-1)/n+1;
	kl=mpm-(c-1)*n;
	if(c%2==1)r=kl;
	else r=n-kl+1;
	cout<<c<<" "<<r;
	
	return 0;
}
