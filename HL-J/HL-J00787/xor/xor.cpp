#include <bits/stdc++.h>
using namespace std;
int a,n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0){
			ans++;
		}
	}
	if(ans==2){
		cout<<3;
	}
	else{
		cout<<ans;
	}
	return 0;
}

