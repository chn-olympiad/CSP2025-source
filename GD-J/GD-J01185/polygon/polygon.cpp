#include <bits/stdc++.h> 
using namespace std;
using ll=long long;

ll n,a[10000],c=0,su=0,ma=0,x=0;
bool used[10000]={false};
bool check(){
	return su>ma*2;
}
void f(ll m,ll k){
	if(k>=m){
		if(check()){
			c++;
		}
		return;
	}
	for(ll i=0;i<n;i++){
		if(used[i]){
			continue;
		}
		if(a[i]>ma){
			ma=a[i];
		}
		su+=a[i];
		used[i]=true;
		f(m,k++);
		used[i]=false;
		su-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	else{
		f(3,0);
		//for(ll i=3;i<=n;i++){
		
		//}
		cout<<c;
	}
	return 0;
}
