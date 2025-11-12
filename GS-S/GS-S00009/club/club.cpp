#include<bits/stdc++.h>
using namespace std;

int sans=0;

struct p{
	int x,y,z;
}a[100010];
bool cmp1(p m,p _n){
	return m.x>_n.x;
}
bool cmp2(p m,p _n){
	return m.y>_n.y;
}
bool cmp3(p m,p _n){
	return m.z>_n.z;
}
int n;
void dfs(int k=1,int d=0,int e=0,int f=0,int s=0){
	if(k>n){
		sans=max(sans,s);
		return;
	}
	if(d<n/2||a[k].x==0)dfs(k+1,d+1,e,f,s+a[k].x);
	if(e<n/2||a[k].y==0)dfs(k+1,d,e+1,f,s+a[k].y);
	if(f<n/2||a[k].z==0)dfs(k+1,d,e,f+1,s+a[k].z);
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--){
		//int dp[100010];
		sans=0;
		bool A=1,B=1,C=1;
		n=read();
		for(int i=1;i<=n;i++){
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			if(a[i].x!=0){B=0;C=0;}
			if(a[i].y!=0){A=0;C=0;}
			if(a[i].z!=0){A=0;B=0;}
		}
		if(A){
			sort(a+1,a+n+1,cmp1);
			int ansa=0;
			for(int i=1;i<=n/2;i++){
				ansa+=a[i].x;
			}
			cout<<ansa<<endl;
		}else if(B){
			sort(a+1,a+n+1,cmp2);
			int ansb=0;
			for(int i=1;i<=n/2;i++){
				ansb+=a[i].y;
			}
			cout<<ansb<<endl;	
		}else if(C){
			sort(a+1,a+n+1,cmp3);
			int ansc=0;
			for(int i=1;i<=n/2;i++){
				ansc+=a[i].z;
			}
			cout<<ansc<<endl;
		}else{
			dfs();
			cout<<sans<<endl;
		}
	}
	return 0;
}
