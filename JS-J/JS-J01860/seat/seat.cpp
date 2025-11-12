#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,x,a[1000010],r=1,c=1,step=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,greater<ll>());
    while(a[step]!=x){
        step++;
        ll dr=r+(c&1?1:-1);
        if(1>dr||n<dr) c++;
        else r=dr;
    }
    cout<<c<<' '<<r;
	return 0;
}
