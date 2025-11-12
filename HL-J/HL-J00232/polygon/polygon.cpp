#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,h;
int r=1,s=1,t=1;
int f[5001],g[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>f[i];
		g[i]=9000;
	}
	for(int j=1;j<=a;j++){
		for(int n=1;n<=a;n++){
			g[j]=min(g[j],f[n]);
		}
		for(int n=1;n<=a;n++){
			if(g[j]==f[n]&&b!=2){
				f[n]=10000;
				b=2;
			}
		}
		b=0;
	}
	for(int i=1;i<=a;i++){
		c+=g[i];
	}
	d=g[3]*2;
	if(c>d){
		cout<<1;
	}
	else if(c<=d){
		cout<<0;
	}
	return 0;
}
