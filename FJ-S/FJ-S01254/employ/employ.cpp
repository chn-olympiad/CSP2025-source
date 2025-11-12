#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1') ans+=1;
	}
	if(ans>=m){
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}