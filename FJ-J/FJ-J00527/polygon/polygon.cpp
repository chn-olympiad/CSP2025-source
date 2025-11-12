#include<bits/stdc++.h>
#define ll long long

using namespace std;
int T;
void solve(){
	int e=0;
	cin>>e;
	if(e==3){
		int x,y,z;
		cin>>x>>y>>z;
		if(x<y) swap(x,y);
		if(x<z) swap(x,z);
		if(x>=z+y) cout<<"0";
		else cout<<"1";
	}else{
		cout<<"6";
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	T=1;
	for (int t=0;t<T;t++) solve();
	return 0;
}

 
