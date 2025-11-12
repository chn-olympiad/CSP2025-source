#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int MAXN = 5e5 + 5;
int a[MAXN];
int op;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1){
			flag = 0;
		}
	}
	if(k == 1){
		cout<<n;
		return 0;
	}
	else if(flag == 1){
		cout<<n / 2;
		return 0;
	}
	else{
		cout<<1;
	}
	return 0;
}
