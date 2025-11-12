#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
struct node{
	int u,v,w;
	bool operator<(const node&b)const{
		return w!=b.w?w>b.w:u!=b.u?u>b.u:v>b.v;
	}
};
int n,m,k,f[100001],x,y,z,s;
priority_queue<node>q;
int gf(int x){
	return f[x]==x?x:f[x]=gf(f[x]);
}
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	while(m--)x=rd(),y=rd(),z=rd(),q.push({x,y,z});
	for(int i=1;i<=k;i++){
		x=rd();
		for(int j=1;j<=n;j++)f[j]=rd();
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++)q.push({j,k,f[j]+f[k]+x});
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;m=0;
	while(q.size()){
		if(m==n-1)break;
		x=gf(q.top().u),y=gf(q.top().v),z=q.top().w,q.pop();
		if(x==y)continue;m++;
		s+=z,f[x]=y;
	}
	cout<<s;
	return 0;
}
