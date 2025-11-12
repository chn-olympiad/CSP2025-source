#include<bits/stdc++.h>
using namespace std;

int a[5005],s,n;

void dfs1(int b,int c,int d){
	int m,z;
	m=max(a[b],a[c]);
	m=max(m,a[d]);
	z=a[b]+a[c]+a[d];
	if(z>m*2) s++;
	if((b==(n-2))&&(c==(n-1))&&(d==n)) return ;
	else if((c==(n-1))&&(d==n)) dfs1(b+1,b+2,b+3);
	else if(d==n) dfs1(b,c+1,c+2); 
	else dfs1(b,c,d+1);
} 

void dfs2(int b,int c,int d,int e){
	int m,z;
	m=max(a[b],a[c]);
	m=max(m,a[d]);
	m=max(m,a[e]);
	z=a[b]+a[c]+a[d]+a[e];
	if(z>m*2) s++;
	if((b==(n-3))&&(c==(n-2))&&(d==(n-1))&&(e==n)) return ;
	else if((c==(n-2))&&(d==(n-1))&&(e==n)) dfs2(b+1,b+2,b+3,b+4);
	else if((d==(n-1))&&(e==n)) dfs2(b,c+1,c+2,c+3);
	else if(e==n) dfs2(b,c,d+1,d+2); 
	else dfs2(b,c,d,e+1);
}

void dfs3(int b,int c,int d,int e,int f){
	int m,z;
	m=max(a[b],a[c]);
	m=max(m,a[d]);
	m=max(m,a[e]);
	m=max(m,a[f]);
	z=a[b]+a[c]+a[d]+a[e]+a[f];
	if(z>m*2) s++;
	if((b==(n-4))&&(c==(n-3))&&(d==(n-2))&&(e==(n-1))&&(f==n)) return ;
	else if((c==(n-3))&&(d==(n-2))&&(e==(n-1))&&(f==n)) dfs3(b+1,b+2,b+3,b+4,b+5);
	else if((d==(n-2))&&(e==(n-1))&&(f==n)) dfs3(b,c+1,c+2,c+3,c+4);
	else if((e==(n-1))&&(f==n)) dfs3(b,c,d+1,d+2,d+3);
	else if(e==n) dfs3(b,c,d,e+1,e+2); 
	else dfs3(b,c,d,e,f+1);
}

int main(){
    freopen("polygon.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3) dfs1(1,2,3);
 	else if(n==4){
		dfs1(1,2,3);
		dfs2(1,2,3,4);
	}
	else if(n==5){
		dfs1(1,2,3);
		dfs2(1,2,3,4);
		dfs3(1,2,3,4,5);
	}	
	cout<<s%998%244%353;
    freopen("polygon.out","w",stdout);
    return 0;
}
