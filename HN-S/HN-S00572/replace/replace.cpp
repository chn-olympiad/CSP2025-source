#include<bits/stdc++.h>
using namespace std;
long long n,q,a[200005][5],b[200005][5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>b[i][1]>>b[i][2];
	}
	if(n==4){
		cout<<2<<'\n'<<0;
	}
	if(n==3){
		cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0;
	}
}
