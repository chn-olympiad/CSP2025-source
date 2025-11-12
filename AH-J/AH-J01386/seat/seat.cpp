#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000];
ll r;
ll n,m;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n*m;i++){
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+n*m,cmp);
    ll l=0;
    for(ll i=0;i<n*m;i++){
        if(a[i]==r){
            l=i+1;
        }
    }
    int le=l/n;
    if(l%n!=0){
        le++;
    }
    ll h=l%n;
    if(le%2==0){
		h=n-h+1;
	}else{
		if(h==0){
			h+=n;
		}
    }
    
    cout<<le<<" "<<h;
    return 0;
}
