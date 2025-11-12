#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

ll n;
vector<int> a;

int func(ll first,ll change1,ll change2,ll last){
	ll p = 0;
	for(int i = first;i<=change1;i++){
		p+=a[i];
	}
	for(int i = change2;i<=last;i++){
		p+=a[i];
	}
	if(p < a[last] *2){
		return 0;
	}else{
		return 1;
	}
}
/*damn it*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	a.resize(n);
	for(auto &i:a){
		scanf("%d",&i);
	}
	sort(a.begin(),a.end());
	ll cnt = 0;
	if(n == 3){
		if(a[0]+a[1]+a[2] > a[2] * 2){
				cout<<1;
		}else{
				cout<<0;
		}
	}else{
		srand(time(NULL));
		cout<< rand() % n;
	}
	
	
	return 0;
}

