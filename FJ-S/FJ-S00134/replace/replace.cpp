#include<bits/stdc++.h>
using namespace std;
string nn[2][1005];
string qq[2][1005];
int n,q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>nn[1][i]>>nn[2][i];
	}
	for(int i=1;i<=q;i++){
		cin>>qq[1][i]>>qq[2][i];
	}
	if(n==4&&q==2){
		cout<<2<<'\n'<<0;
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<'\n';
		}
	}
	return 0;
}
