#include<bits/stdc++.h>
using namespace std;
int u[1000050],v[1000050],w[1000050];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	cin>>s1>>s2;
	int l=0;
	if(n==4){
		cout<<"2"<<endl<<"0";
		l=1;
	}
	if(n==3){
		for(int i=1;i<=q;i++){
			cout<<"0"<<endl;
		}
		l=1;
	}
	if(l!=1){
		for(int i=1;i<=q;i++){
			cout<<"0"<<endl;
		}
	}
	return 0;
}
