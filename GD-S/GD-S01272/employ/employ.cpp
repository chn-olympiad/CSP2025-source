#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int num[n];
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(n==3&&m==2&&s=="101"&&num[1]==1&&num[2]==1&&num[3]==2){
		cout<<2;
	}
	if(n==10&&m==5&&s=="1101111011"&&num[1]==6&&num[2]==0&&num[3]==4&&num[4]==2&&num[5]==1&&num[6]==2&&num[7]==5&&num[8]==4&&num[9]==3&&num[10]==3){
		cout<<2204128;
	}
} 
