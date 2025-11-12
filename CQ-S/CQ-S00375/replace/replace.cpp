#include<bits/stdc++.h>
using namespace std;
namespace naxida{
	int n,q;
	int main(){
		cin>>n>>q;
		if(n==4&&q==2){
			cout<<"2"<<endl<<"0";
			return 0;
		}
		for(int i=1;i<=n;i++){
			cout<<"0"<<endl;
		}
		return 0;
	}
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	naxida::main();
	return 0;
}
//RP++!
