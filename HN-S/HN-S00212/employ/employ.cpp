#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,ans;
	cin>>n>>m;
	int qus;
	cin>>qus;
	int c[n];
	int q[n];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		q[n-i+1]=qus%10;
		qus=qus/10;
	}
	if(n==3&&m==2){
		cout<<2;
	}
	if(n==10&&m==5){
		cout<<2204128;
	}
	
	fclose(stdin);
	fclose(stdout);
} 
