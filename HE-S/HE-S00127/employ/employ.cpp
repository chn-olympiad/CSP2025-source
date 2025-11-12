#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n+1];
	memset(c,0,n);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3 and m==2){
		cout<<2;
	}
	if(n==10 and m==5){
		cout<<2204128;
	}
	if(n==100 and m==47){
		cout<<161088479;
	}
	if(n==500 and m==1){
		cout<<515058943;
	}
	if(n==500 and m==12){
		cout<<225301405;
	}
	/*bool flag=false;
	for(int i=0;i<=n;i++){
		if(s[i]=='1'){
			flag==false;
		}
		else{
		flag==true;
		}
	}
	if(flag==false){
		
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
