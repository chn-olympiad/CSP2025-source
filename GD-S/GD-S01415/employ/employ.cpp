#include<bits/stdc++.h>
using namespace std;
int n,m;string s;
int c[10000];
bool in(string x){
	for(int i=1;i<=x.length();i++){
		if(x[i]==0)return false;
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=0;
	if(in(s)){
		for(int i=1;i<=m;i++){
			ans*=i;
		}
		for(int i=1;i<=n-m;i++){
			ans*=2;
		}
		cout<<ans;	
	}
	if(m==n){
		
		for(int i=1;i<=m;i++){
			ans*=i;
		}
		cout<<ans;
	}
	return 0;
} 
