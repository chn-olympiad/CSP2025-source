#include <bits/stdc++.h>
using namespace std;
int s[5005],sum,a,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	if(n<=2){
		cout << 0;
		return 0;
	}else{
		a=max(max(s[1],s[2]),s[3]);
		if(s[1]+s[2]+s[3]>a*2) cout << 1;
		else cout << n/2;
	}
	return 0;
}
