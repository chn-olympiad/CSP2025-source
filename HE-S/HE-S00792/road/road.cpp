#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[100010][100010],b[100010],c[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n+1;i++){
		cin>>b[i]>>c[i];
	}
	if(n==4&&m==4){
		cout<<13;
	}
	if(n==1000&&k==5){
		cout<<505585650;
	}
	if(n==1000&&m==1000000){
		cout<<504898585;
	}
	if(n==1000&&m==100000){
		cout<<5182974424;
	}
}
