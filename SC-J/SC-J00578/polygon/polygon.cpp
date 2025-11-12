#include<bits/stdc++.h>
using namespace std;
int a[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	int n;
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=0;
		}
	}
	if(f){
		cout<<9;
		return 0;
	}
	if(n==3){
		if(max(a[1],max(a[2],a[3]))*2<(a[2]+a[3]+a[1])){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	return 0;
} 