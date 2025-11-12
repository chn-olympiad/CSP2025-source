#include<bits/stdc++.h>
using namespace std;
int jg=0;
int n;
int x[5005]={0};
void js(int s,int zs,int j,int zd){
	if(s>=3){
		if(zs>zd+zd){
			jg++;
		}
	}
	for(int i=j;i<n;i++){
		if(x[i]>zd) zd=x[i];
		js(s+1,zs+x[i],i+1,zd);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	int zd=0;
	js(1,0,0,zd);
	cout<<jg%998244353;
	
	return 0;
}
