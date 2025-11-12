#include<bits/stdc++.h>
using namespace std;
int mo = 998244353;
int n,l[5005],a;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> l[i];
	}
	sort(l+0,l+n);
	if(n==3){
		if(l[3]<l[1]+l[2])cout << 1 <<endl;
		else cout << 0 <<endl;
		return 0;
	}
	if(l[n]==1){
		for(int i = 1;i<=n-2;i++){
			a=(a%mo+i%mo)%mo;
		}
		cout << a <<endl;
		return 0;
	}
	if(n<3)cout << 0 <<endl;
	
	return 0;
}
