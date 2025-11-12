#include<bits/stdc++.h>
#define ll long long
using namespace std;
void d(ll a[],ll n,ll m,ll &ans,ll start){
	//cout << 'm' << m << 'a' << ans << 's' << start << endl;
	if(start+m>n) return;
	ll max = 0,sub = 0;
	//cout << 'e';
	for(int i=start;i<start+m;i++){
		if(a[i]>max) max = a[i];
		sub+=a[i]; 
		//cout << a[i] << ' ';
	}
	//cout << endl;
	if(sub>max*2){
		ans++;
		/*cout << 't';
		for(int i=start;i<start+m;i++){
			cout << a[i] << ' '; 
		}
		cout << endl;*/
	}
	d(a,n,m,ans,start+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ll n;
	cin >> n;
	ll a[n+1] = {},ans = 0;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	for(ll m=3;m<=n;m++){
		d(a,n,m,ans,m-3+1);
	}
	for(ll m=1;m<=n*2;m++){
		 if(m>=3){
		 	for(int i=1;i<=m;i++){
		 		if(i+m-1>n) continue;
		 		ll max = 0,sub = 0;
		 		//cout << 'p';
		 		for(int j=i;j<=i+m-1;j++){
		 			//if(a[j]>a[j+1]) continue;
		 			if(a[j]>max) max = a[j];
		 			sub+=a[j];
		 			//cout << a[j] << ' ';
				 }
				 //cout << endl;
				 if(sub>max*2){
				 	/*cout << 't';
				 	for(int j=i;j<=i+m-1;j++){
		 				cout << a[j] << ' ' ;
				 	}
				 	cout << endl;*/
				 	ans++;
				 }
			 }
		 }
	}
	cout << ans%998244353;
	return 0;
}
