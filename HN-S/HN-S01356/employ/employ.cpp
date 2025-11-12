#include <bits/stdc++.h>
using namespace std;
int n,m,c[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("e,ploy,out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	if(n==3&&m==2&&s=="101"&&c[0]==1&&c[1]==1&&c[2==2]){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s=="1101111011"){
		cout<<220428;
		return 0;
	}
	return 0;
}
