#include<bits/stdc++.h>
using namespace std;
int n,k,q,t,rr,a[3010][30],b[3010],c[30],f[3010][3010],g[3010];
void l(int x,int y,int z,int p){
	if(z==21){
		return;
	}
	if(x-y>=0){
		a[p][z]=1;
		l(x-y,y/2,z+1,p);
	}
	else{
		l(x,y/2,z+1,p);
	}
}
void ll(int x,int y,int z){
	if(z==21){
		return;
	}
	if(x-y>=0){
		c[z]=1;
		ll(x-y,y/2,z+1);
	}
	else{
		ll(x,y/2,z+1);
	}
}
int lll(int x){
	int xx=0;
	int w=pow(2,19);
	for(int i=1;i<=20;i++){
		if(a[x][i]!=c[i]){
			xx+=w;
		}
		w/=2;
	}
	return xx;
}
void qq(int x){
	if(x>n){
		rr=max(rr,t);
		return;
	}
	if(g[x]!=0x3f3f3f3f){
		t++;
		qq(g[x]+1);
		t--;
	}
	qq(x+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	q=pow(2,19);
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++){
		cin>>b[i];
		l(b[i],q,1,i);
	}
	for(int i=1;i<=n;i++){
		f[i][i]=b[i];
		if(f[i][i]==k){
			g[i]=min(g[i],i);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			memset(c,0,sizeof(c));
			ll(f[i][j-1],q,1);
			f[i][j]=lll(j);
			if(f[i][j]==k){
				g[i]=min(g[i],j);
			}
		}
	}
	qq(1);
	cout<<rr;
	return 0;
}
