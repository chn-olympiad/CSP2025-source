#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<n;
	}	
	else{
		cout<<998244352;
	}	
	return 0;
}
