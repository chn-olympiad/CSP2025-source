#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[106];
ll sc,c,r,pm;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n*m;++i){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i = 1;i <= n*m;++i){
		if(a[i]==sc){
			pm=i;
			break;
		}
	}
	c=pm/n;
//	cout << pm << " " << n << " "<<pm/n <<" " << pm%n << endl;
	if(pm%n!=0){
		c++;
	}
	cout << c << " ";
	pm-=n*(c-1);
	if(c%2==1){
		cout << pm;
	}
	else{
		cout<<n-pm+1;
	}
	cout << endl;
	return 0;
} 
/*
7 4
8 7 6 5 3 1 2 4 10 9 17 13 24 14 12 25 36 37 38 39 40 43 44 55 56 51 52 53
*/
