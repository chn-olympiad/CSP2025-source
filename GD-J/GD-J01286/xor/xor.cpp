#include<bits/stdc++.h>
using namespace std;
int ca[32]={2097152,1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
int s[500000],o=0;int n,k;
bool g[500000];
int y=0; 
string ty(int r){
	string h;
	while(r){
		h+=r%2;
		r/2;
	}
	return h;
}
int rr(int c,int d){
	string a=ty(c),b=ty(d);
	int h[64]={};
	for(int i=0;i<max(a.size(),b.size());i++){
		h[i]=max(a[i],b[i])%min(a[i],b[i]);
	}
	int y=0;
	for(int i=max(a.size(),b.size())-1;i>=0;i--){
		y+=h[i]*ca[i];
	}
	return y;
}
int df(int u,int i){
	g[u]=1;int l=rr(s[u],i);
	y+=l;int v;
	if(y>k){
		y=0; 
		return 0;
	}
	else if(y==k){
		o++;y=0;
		return 1;
	}
	else if(y<k&&!g[u]){
		v=df(u+1,l);
	}
	if(!v){
		y-=i;
		g[u]=0;
	}
	else{
		y=0;
		return 1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		if(!g[i]){
			
		}
		else{
			df(i,0);
		}
	}
	cout<<o;
} 
