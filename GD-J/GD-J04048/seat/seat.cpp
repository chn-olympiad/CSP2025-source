#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[110];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll a1=a[1],id;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<' ';
		if(a[i]==a1){
			id=i;
			break;
		}
	}
	//cout<<a1<<' '<<id<<'\n';
	ll ans=ceil(id*1.0/n*1.0),ans1=id-(ans-1)*n;
	if(ans%2==1){
		cout<<ans<<' '<<ans1;
	}else{
		cout<<ans<<' '<<n-ans1+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
