#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=' ';
	int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum;
}
int T,n,m,k;
struct Edge{
	int u,v,w;
}edge[1000006];
vector<Edge>e[1004];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int f[10004];
int findf(int x){
	if(f[x]==x)return x;
	return f[x]=findf(f[x]); 
}
int gz[15][1004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	}
	for(int i=0;i<=k;++i){
		if(i!=0){
			for(int j=0;j<=n;++j){
				gz[i][j]=read();
			}
		}
		else for(int j=1;j<=n;++j)gz[i][j]=0x3f3f3f3f;
	}
	sort(edge+1,edge+1+m,cmp);
	int cnt=1,sum=0;
	for(int i=1;i<=m&&cnt<n;++i){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int A=findf(u),B=findf(v);
		if(A==B)continue;
		e[u].push_back((Edge){u,v,w});
		e[v].push_back((Edge){v,u,w});
		sum+=w;
		++cnt;
		f[A]=B;
		
	}
	cout<<sum;
} 
/*
Fisrt impression:The minest tree
Second:What the problem mean???
After writing a code:Oh no!My idea is wrong!
Now:QwQ.
Maybe 16pts

Uid:753204 mywzj_mo
bits\stdc++.h
//freopen
freeopen
freopen("road.out","r",stdin)
freopen("road.in","w",stdout)
int mian(){
cnt_broken=4;

Five nights at Freedy's:
We are wating everynight to final roam and invite
newcomers to play with us.
For many years we've been alone.
We're forced to be/forget the sing word/
/Tried to write/

I'll put you back.(?)
--Don't forget to check your bed to make sure there is no nightmare Freddy here.

Look!It's Foxy!He is running to us!
Flashlight!(Oh,what a bad guy!I must leave.)
Now we are safe for now,he left.

How do you think cupcake?

My friend:XDB(Baned User),PuShuai(Not oier).
------They ask me to write them into the code.

*/

