#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[110],cur;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll s=n*m;
	for(ll i=1;i<=s;i++){
		cin>>a[i];
	}
	cur=a[1];
	sort(a+1,a+s+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==cur){
			cur=i;
			break;
		}
	}
	
	if(cur/n==0){
		cout<<"1 "<<cur%n;
		return 0;
	}
	else{
		if(cur%n==0){
			if((cur/n)%2==0)	cout<<cur/n<<" 1";
			else 	cout<<cur/n<<" "<<n;
			return 0;
		}
		else{
			cout<<cur/n+1<<" ";
			if(cur<=2*n){
				if(cur>n)	cout<<n-cur%n+1;
				else cout<<cur%n;
			}
			else{
				while(cur>2*n){
					cur-=2*n;
				}
				if(cur>n)	cout<<n-cur%n+1;
				else cout<<cur%n;
			}
		}
	}
	return 0;
}
