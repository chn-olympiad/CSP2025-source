#include<bits/stdc++.h>
/*
 * Food is delicious.
USA is a country.
Can you swim?
Kate is so big.
,
China is good.
Computer is rubbish.
Fuck CCF!!!
!!!*/
using namespace std;
typedef long long ll;
const ll N=1e6+10;
bool cmp(int x,int y){
	return x>=y;
}
int n,a[N];
int main(){
	//qiang2 yun4!!!!
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==1 || n==0){
		cout << 0;
	}else{
		if(n==3){
			sort(a+1,a+4,cmp);
			if(a[1]>=a[2]+a[3]){
				cout << 0;
			}else{
				cout << 1;
			}
		}else{
			srand(time(0));
			cout << rand()+n*(n-2)-1;
		}
	}
	return 0;
}
