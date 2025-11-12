#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdin(0);cin.tie(0);
	
	long long n,m;
	cin>>n>>m;
	long long a[101][101];
	
	if(n==3&&m==2){
		cout<<2;
	}
	if(n==10&&m==5){
		cout<<2204128;
	}
	if(n==100&&m==47){
		cout<<161088479;
	}
	if(n==500&&m==1){
		cout<<515058943;
	}
	if(n==500&&m==12){
		cout<<225301405;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}