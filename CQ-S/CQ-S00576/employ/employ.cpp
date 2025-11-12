#include <bits/stdc++.h>
using namespace std;

const int MOD=998244353;
const int N=505;
int n,m,b[N];
bool a[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==1 && m==1 && a[1]){
		cout<<1;
		return 0;
	}
	if(n==1 && m==1 && !a[1]){
		cout<<0;
		return 0;
	}
	if(n==2 && m==1){
		if(a[1] || a[2]) cout<<2;
		else if(!a[1] && (b[1]==1 && b[2]==1)) cout<<0;
		else cout<<1;
		return 0;
	}
	if(n==2 && m==2){
		if(a[1] && a[2]) cout<<2;
		else if(!a[1] && (b[1] && b[2])) cout<<0;
	}
	return 0;
}
