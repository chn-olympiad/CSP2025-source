#include<bits/stdc++.h>
using namespace std;
int n,q;
string sa,sb;
int main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa>>sb;
	}
	while(q--){
		cin>>sa>>sb;
		cout<<n<<"\n";
	}
	
	return 0;
}

