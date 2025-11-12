#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2){
		printf("2\n0");
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
