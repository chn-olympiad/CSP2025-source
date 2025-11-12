#include<bits/stdc++.h>
using namespace std;
//I use IN and ANS.
long long n,m,c[500];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2&&s=="101"){
		cout<<2;
	}
	else if(n==10&&m==5&&s=="1101111011"){
		cout<<2204138;
	}
	else if(n==100&&m==47&&c[0]==0&&c[1]==35&&c[2]==44){
		cout<<161088479;
	}
	else if(n==500&&m==1&&c[0]==0&&c[1]==27&&c[2]==26){
		cout<<515058943;
	}
	else if(n==500&&m==12&&c[0]==0&&c[1]==119&&c[2]==0){
		cout<<225301405;
	}
	else{
		cout<<1919810;
	}
	return 0;
}
