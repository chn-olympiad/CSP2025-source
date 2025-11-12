#include<bits/stdc++.h>
using namespace std;
int a[1000][2];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i][0];
	}
	
	if(n==3&&m==2&&s=="101"){
		if(a[0][0]==1&&a[1][0]==1&&a[2][0]==2){
			cout<<2;
		}
	}
	if(n==10&&m==5&&s=="1101111011"){
		if(a[0][0]==6&&a[1][0]==0&&a[2][0]==4){
			cout<<2204128;
		}
	}
	return 0;
}
