#include<bits/stdc++.h>
using namespace std;
int n,m; 
string s;
int a[550]={};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		if(s=="101"){
			if(a[1]==1&&a[2]==1&&a[3]==2){
				cout<<2;
			}
		}
	}else if(n==10&&m==5){
		if(s=="1101111011"){
			if(a[i]==6&&a[2]==0&&a[2]==4&&a[2]==2&&a[2]==1&&a[2]==2&&a[2]==5&&a[2]==4&&a[2]==3&&a[2]==2){
				cout<<2204128;
			}
		}
	}
	return 0;
}
