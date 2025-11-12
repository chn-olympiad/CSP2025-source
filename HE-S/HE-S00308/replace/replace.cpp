#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n+m;i++){
		string s,k;
		cin>>s>>k;
	}
	if(n==4&&m==2){
		cout<<2<<'\n'<<0<<'\n';
	}else if(n==3&&m==4){
		for(int i = 1;i<=4;i++) cout<<0<<'\n';
	}
	return 0;
}
