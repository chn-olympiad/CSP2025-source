#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define modd 998244353
using namespace std;

ll n;
ll a[N];

ll ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<(1<<n);i++){
//		cout<<i<<endl;
		ll k=0,sum=0,maxx=0;
		for(ll j=1;j<=n;j++){
			ll l=i>>(j-1);
			if(l&1){
//				cout<<(i>>(j-1))<<endl;
				sum+=a[j];
				maxx=j;
				k++;
			}
		}
		if(sum>2*a[maxx]&&k>=3)ans++;
	}
	cout<<ans%modd;
	return 0;
}


/*
5
1 2 3 4 5

9
*/

/*
5
2 2 3 8 10

6
*/
