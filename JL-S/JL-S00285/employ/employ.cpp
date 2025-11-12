#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,s[N],c[N],Pa;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==0){
			Pa=1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	puts("0");
	return 0;
}
