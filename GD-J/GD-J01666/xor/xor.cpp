#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500010],cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n,k;
	cin >> n >> k;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll i = 1,j = 1,t = 0,z;
	while(i <= n){
		t = 0;
		for(z = i;z <= j;z++){
			t=(t^a[z]);
		}
//		cout << t << " "<< i << " "<< j << endl;
		if(t == k){
//			cout << i << " " << j<< endl;
			j++;
			i=j;
			cnt++;
		}
		else if(t > k){
			i++;
			j=i;
		}
		else if(t < k){
			j++;
		}
		if(j > n){
			i++;
			j=i;
			continue;
		}
	}
	cout << cnt;
	return 0;
}
