#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s[105],i=1,j=1,a;
bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>s[i];
	a=s[1];
	sort(s+1,s+1+n*m,cmp);
	bool p=0;
	ll b=1;
	for(ll x=1;x<=n*m;x++){
		if(p==0){
			while(i<=m){
				if(s[b]==a){
					cout<<j<<" "<<i;
					return 0;
				}
				i++;
				b++;
			} 
			i--;
			j++;
			p=1;
		}
		if(p==1){
			while(i>=1){
				if(s[b]==a){
					cout<<j<<" "<<i;
					return 0;
				}
				i--;
				b++;
			} 
			i++;
			j++;
			p=0;
		}	
	}
	return 0;
}
