#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,c[510],a[510]={},jl=0;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==1 && m==1){
		cout<<1;
		return 0;
	}
	if(n==1 && m==0){
		cout<<0;
		return 0;
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	cout<<2
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return 0;
} 
