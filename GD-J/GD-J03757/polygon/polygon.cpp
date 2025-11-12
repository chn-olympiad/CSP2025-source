#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
const int MOD = 998244353;
int c[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<3){
		cout<<0%MOD;
		return 0;
	}
	if(n == 3){
		int a = c[1]+c[2];
		int b = c[1]+c[3];
		int x = c[2]+c[3];
		if(a>c[3]&&b>c[2]&&x>c[1]){
			cout<<1%MOD;
			return 0;
		}
		cout<<0%MOD;
	}
	return 0;
}
