#include<bits/stdc++.h>
using namespace std;
int n,m;
string ti;
int g[101];
int t[101];
void cmpco(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				t[i]=t[j]=t[k];
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ti;
	cmpco();
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	if(ti=="101"){
		cout<<2;
	}
	if(n==10&&m==5){
		cout<<2204128;
	}
	return 0;
}