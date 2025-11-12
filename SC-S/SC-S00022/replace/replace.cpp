#include<bits/stdc++.h>
using namespace std;
string x[200500],y[200500];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a==b){
			cout<<n<<endl;
		}else{
			cout<<0;
		}
	}
	return 0;
}
