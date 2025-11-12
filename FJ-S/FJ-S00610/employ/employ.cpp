#include<bits/stdc++.h>
using namespace std;
int c[510]={};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
    for(int i=1;i<=n;i++){
    	if(c[i]==1||c[i]==2) cout<<2<<endl;
	}
	return 0;
}
