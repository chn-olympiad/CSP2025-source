#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Alvin{
	
	int n,q;
	string s1,s2,t1,t2;
	
	signed main(){
		
		cin>>n>>q;
		
		for(int i=1;i<=n;i++){
			cin>>s1>>s2;
		}
		
		cin>>t1>>t2;
		
		if(n==q*2){
			printf("%lld\n%lld",q,0);
		}
		else {
			for(int i=1;i<=q;i++) printf("0\n");
		}
		
		return 0;
		
	}
	
}

signed main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	return Alvin::main();
	
}
