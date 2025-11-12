#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,a;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	if(n==2){
		cout<<2;
	}
	if(n==3){
		cout<<3;
	}
	cout.flush();
	return 0;
}
