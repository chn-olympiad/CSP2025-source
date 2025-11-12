#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int main(){
	freopen("employ.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		bool cu;
		cin>>cu;
		if(cu){
			t++;
		}
	}
	if(t<m){
		cout<<0;
	}else{
		cout<<1;
	}
	for(int i=1;i<=n;i++){
		int cu;
		cin>>cu;
	}
	freopen("employ.out","w",stdout);
}

