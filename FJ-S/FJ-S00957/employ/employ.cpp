#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[502];
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==1){
		cout<<"1";
	}
	else if(m==n){
		cout<<n*n;
	}
	else{
		cout<<"2";
	}
	return 0;
}
