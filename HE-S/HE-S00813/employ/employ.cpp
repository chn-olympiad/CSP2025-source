#include <bits/stdc++.h>
using namespace std;
int n,m;
int ant;
char s[501];
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'){
			ant++;
		}
	}for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		long long ant=1;
		for(int i=1;i<=n;i++){
			ant*=i;
		}
		cout<<ant%998244353;
	}
//	else if(ant==n){
//		
//	}
	return 0;
}
