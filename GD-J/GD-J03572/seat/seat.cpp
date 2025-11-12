#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,m;
ll a[N],s,x,y;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			x=(i+n-1)/n;
			y=i-(i/n)*n;
			cout<<x<<' ';
			if(y==0){
				cout<<n;
				return 0;
			}
			if(x&1) cout<<y;
			else cout<<n-y+1;
			return 0;
		}
	}
	return 0;
}
