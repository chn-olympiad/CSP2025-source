#include<bits/stdc++.h>
using namespace std;

int read(){
	int ans=0,d=getchar();
	bool f=0;
	for(;!isdigit(d);d=getchar()) f=(d=='-');
	for(;isdigit(d);d=getchar()) ans=ans*10+d-'0';
	return f ? -ans : ans;
}
const int N=1e4+10;
int s[N]; 
int d[N];
int n,m,k;

void add(int n){
	for(int i=1;i<=n;i++){
		s[i]=i;
		d[i]=0;
	}
}

int find(int x){
	if(s[x]!=x){
		int t=d[x];
		s[x]=find(s[x]);
		d[x]+=t;
	}
	return s[x];
}

void update(int x,int y,int w){
	int rootx=find(x),rooty=find(y);
	if(rootx!=rooty){
		s[rootx]=y;
		d[rootx]+=w-d[x]; 
	}
	
}

signed main(){
	
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	
	n=read(),m=read(),k=read();
	add(n);
	for(int i=1;i<=m;i++){
		int x,y,z;
		x=read(),y=read(),z=read();
		if(x<y) update(x,y,z);
		else update(y,x,z);
	}
	
	return 0;
}


