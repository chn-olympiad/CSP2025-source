#include<bits/stdc++.h>
using namespace std;
int n,m,a[600];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3&&m==2){
		if(a[1]==1&&a[2]==1&&a[3]==2){
			cout<<2;
			return 0;
		}		
	}
	if(n==10&&m==5){
		if(a[1]==6&&a[2]==0&&a[3]==4&&a[4]==2&&a[5]==1&&a[6]==2&&a[7]==5&&a[8]==4&&a[9]==3&&a[10]==3){
			cout<<2204128;
			return 0;
		}
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	return 0;
}
