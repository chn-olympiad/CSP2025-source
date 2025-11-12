#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n,q;
int res;
string t,tt;
string x[N],y[N];

void solve(){
	for(int i=1;i<=n;i++){
		if(t==x[i]&&tt==y[i]) res++;
	}
}

int main(){
	freopen("replace4.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		cin>>t>>tt;
		solve();
		cout<<res<<'\n';
		res = 0;
	}
	return 0;
}
//Shawty its so freaking heartache
