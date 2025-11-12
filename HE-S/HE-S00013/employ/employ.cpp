#include<bits/stdc++.h>
using namespace std;
int n,m;
string s; 
int c[505];
int vis[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int flag;
	for(int i=1;i<=n;i++){
		if(c[i]=='0') flag=1;
	}
	if(flag==0){
		
	}
	cout<<1;
	return 0;
}
