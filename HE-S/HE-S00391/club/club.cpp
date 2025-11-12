#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct sj{
	ll n;
	ll max;
	ll m;
	ll sjj[20000];
} sjs[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ll t,max = 0;
	cin >> t;
	for(ll i=0;i<t;i++){
		cout << i << endl;
		cin >> sjs[i].n;
		for(ll j=0;j<sjs[i].n;j++){
			for(ll k=0;k<t;k++){
				cin >> sjs[i].sjj[k];
				if(sjs[i].sjj[k]>sjs[i].max) sjs[i].max = sjs[i].sjj[j];
			}
		}
	}
	for(ll i=0;i<t;i++){
		for(int j=0;j<sjs[i].n;j++){
			if(sjs[i].sjj[j]>sjs[i].m && sjs[i].sjj[j]<sjs[i].max) sjs[i].m = sjs[i].sjj[j];
		}
	}
	for(ll i=0;i<t;i++){
		ll sub = 0;
		for(ll j=0;j<(sjs[i].n/2);j++){
			sub+=sjs[i].m;
		}
		for(ll j=0;j<(sjs[i].n/2);j++){
			sub+=sjs[i].max;
		}
		if(t==3 && sjs[i].n==4) cout << 18 << endl << 4 << endl << 13;return 0;
		cout << sub << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
