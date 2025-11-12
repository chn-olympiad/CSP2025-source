#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool cmp(ll a,ll b){
	return a>b;
}
void solve(){
	ll n,m,a[105],k;
	cin>>n>>m;
	cin>>k;
	a[1]=k;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			k=i;
			break;
		}
	}ll a1,a2;
	a1=(k-1)/n+1;
	a2=(a1%2==1?k-(a1-1)*n:n-(k-(a1-1)*n)+1);
	cout<<a1<<" "<<a2;
}
int main(){
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

