#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010],b[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,cnt=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}for(ll i=3;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll maxn=-1;
			for(ll q=j-i;q<=j;q++){
				maxn=max(maxn,a[i]);
			}if(b[j]-b[j-i+1]>2*maxn){
				cout<<j-i+1<<" "<<j<<"\n";
				cnt++;
			}
		}
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
