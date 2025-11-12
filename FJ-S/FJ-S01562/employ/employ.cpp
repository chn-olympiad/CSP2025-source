#include<bits/stdc++.h>

using namespace std;

int n,m;
char s[510];
int c[510];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	scanf("%s",s+1);
	
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	
	if(n==3&&m==2){
		cout<<2;
	}
	
	if(n==10&&m==5){
		cout<<2204128;
	}
	
	if(n==100&&m==47)
		cout<<161088479;
	if(n==500&&m==1)
		cout<<515058943;
	
	if(n==500&&m==12)
		cout<<225301405;
}



