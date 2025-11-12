#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}M[int(2e6+10)];
int c[11]; 
int c2[11];
int top;
bool cmp(node a,node b){
	return a.w<b.w;
} 
int t[int(1e4+10)];
int find(int node){
	if(t[node]==node){
		return node;
	}
	return t[node]=find(t[node]);
}
int cnt;
int n,m,k;
long long ans=1e18;
long long man(){
		long long tmp=0;
		iota(t,t+n+1+k,0);
		cnt=1;
		sort(M,M+top,cmp);
		for(int j=0;j<top;j++){
			if(cnt==n) break;
			int u=find(M[j].u),v=find(M[j].v);
			if(u!=v){
				tmp+=M[j].w;
				if(v>n) tmp+=c[v-n],c[v-n]=0;
				else cnt++;
				t[u]=v;
			//	cout<<M[j].u<<" "<<M[j].v<<endl;
			}
		}
		//cout<<endl;
		return tmp; 
}
long long read(){
	long long x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cin.tie(0)->sync_with_stdio(0); 
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		M[top].u=u,M[top].v=v,M[top].w=w;
		top++;
	}
	ans=min(ans,man());
	for(int i=1;i<=k;i++){
		c2[i]=read();
		for(int j=1;j<=n;j++){
			w=read();
			M[top].u=j;
			M[top].v=n+i;
			M[top].w=w;
			top++; 
		}
		for(int j=1;j<=k;j++) c[j]=c2[j];
		if(c2[i]<ans)ans=min(ans,man());
	}
	cout<<ans;
	return 0;
} 
