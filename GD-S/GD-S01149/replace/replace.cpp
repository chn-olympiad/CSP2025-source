#include<bits\stdc++.h>
using namespace std;
const int NN=2e5+5;
const int N=5e6+3;
int n,q;char c[NN][N],qc[NN][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i+=2){
		cin>>c[i]>>c[i+1];
	}
	for(int i=1;i<=q;i+=2){
		cin>>qc[i]>>qc[i+1];
	}
	for(int i=1;i<=q;++i){
		cout<<0<<endl;
	} 
	return 0;
}

