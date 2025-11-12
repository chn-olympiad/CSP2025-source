#include<bits/stdc++.h>
#define mo 998244353
#define ll long long
using namespace std;
ll i,j,k,a[5010],n,s;
bool po(ll la,ll ra){
	ll s=0,mx=0;
	for(i=la;i<=ra;i++){
		s+=a[i];
	}
	if(s>2*a[ra])return 1;
	else return 0;
}
void dfs(ll t,ll d){
	if(t>3){
		for(int i=1;i<t;i++){
			if(s-a[i]>d*2)k++;
			cout <<s-a[i]<<" "<<d<<"\n";
		}
	}
	s+=d;
	if(t>n){
		cout <<k%mo;
		return;
	}
	dfs(t+1,a[t+1]);
	s-=d;
	
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout <<1;
		}else cout <<0;
		return 0;
	}
	if(n<3){
		cout <<0;
		return 0;
	}
	dfs(1,a[1]);
	return 0;
}
