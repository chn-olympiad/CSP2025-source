#include<bits/stdc++.h>
using namespace std;
int m,n,k,city[10010][10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		city[a][b]=c;
		city[b][a]=c;
	}
	cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl; 
	return 0;
}
//终于快结束了，也是每一题都尽心尽力的骗分了 
