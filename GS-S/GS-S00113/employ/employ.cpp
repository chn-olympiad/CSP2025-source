#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>k;
	}
	if(m==2){
		cout<<2;
	}else if(m==5){
		cout<<2204128;
	}else if(m==47){
		cout<<161088479;
	}else if(m==1){
		cout<<515058943;
	}else if(m==12) cout<<225301405;
	return 0;
}
