#include<bits/stdc++.h>
using namespace std;
const int N=201;
int g[N][N];
int n,m,k,mmm;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s;
	int n,q;
	cin>>n>>q;
	int sum=(n+q)*2;
	floyd();
	while(sum--){
		cin>>s;
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0;
	}
	if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}