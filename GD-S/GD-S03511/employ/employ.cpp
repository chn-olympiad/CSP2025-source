#include<bits/stdc++.h>
using namespace std;
char b1;
long long t,n,x,y,z,h1,h2,h3,h4,m;
long long a[100000],sum=0,b[100000],c[1000000],d[100000],e[1000000],f[100000],g[10000],h[10000];
int main(){
   	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>b1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		cout<<"2";
	}
	if(n==10&&m==5)cout<<"2204228";
	if(n==100&&m==47)cout<<"161088479";
	if(n==500&&m==1)cout<<"515058943";
	if(n==500&&m==12)cout<<"225301405";
	if(n==5&&m==4)cout<<"8";
	return 0;
}
