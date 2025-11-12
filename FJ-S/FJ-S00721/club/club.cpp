#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	long long n,a,z[100000],x[100000],c[100000],k=0,l=0,g=0,co=0;
	long long mx[100000]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
	for(int j=0;j<a;j++){
		cin>>z[j]>>x[j]>>c[j];
	}
	for(int j=0;j<a;j++){
		k=max(z[j],x[j]);
		l=max(k,l[j]);
		mx[g]=l;
		g++;
	}
	for(int j=0;j<a;j++){
		if(z[j]==mx[j]){
			z[j]=0;
			continue;
		}
		if(x[j]==mx[j]){
			x[j]=0;
			continue;
		}
		if(z[j]==mx[j]){
			z[j]=0;
			continue;
		}
	}
	for(int i=1;i<=l;i++){
		co=co+mx[i];
	}
	cout<<co<<endl;
	mx[10000]={};
	co=0;
}
	return 0;
}
