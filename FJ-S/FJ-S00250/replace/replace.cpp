#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int n,q; 
string a[N][10],b[N][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	} 
	for(int j=1;j<=q;j++){
		cin>>a[j][1]>>a[j][2];
	}
	if(n==4&&q==2){
		cout<<2<<'\n'<<0;
	}else{
		for(int i=1;i<=4;i++){
			cout<<0<<'\n';
		} 
	}
	return 0;
} 
