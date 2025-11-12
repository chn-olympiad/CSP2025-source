#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int read(){
	int num=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){f=(~f+1);}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar();
	}
	return num*f;
}
int t,n,f[500][500][500];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
	       	int a=read(),b=read(),c=read();
	       	for(int A=n/2;A>=0;A--){
	       	   for(int B=n/2;B>=0;B--){
	       	   	   for(int C=n/2;C>=0;C--){
	       	   	   	   if(A>=1)f[A][B][C]=max(f[A][B][C],f[A-1][B][C]+a);
	       	   	   	   if(B>=1)f[A][B][C]=max(f[A][B][C],f[A][B-1][C]+b);
	       	   	   	   if(C>=1)f[A][B][C]=max(f[A][B][C],f[A][B][C-1]+c);
					   }
				  }	
			}
		}
		cout<<f[n/2][n/2][n/2]<<endl;
	}
	return 0;
}
