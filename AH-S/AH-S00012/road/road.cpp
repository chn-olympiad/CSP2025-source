#include<bits/stdc++.h>
using namespace std;
/*
在不考虑k的情况下这道题是一个裸的最小生成树
有四个点，16分防保龄



接下来就是思考加入k的情况
假如我加入了一个点
他能给出的贡献为他能够沟通两个节点后相差的w-自身的价值v
算了两个小时了先跳
*/



/*
OI啊能不能放过我这一次
有时候明明很累却不知道为什么要坚持
T1写不出来的现实击碎我心中坚强的城池
擦干眼泪冲向上课的日子
一笑了之
*/
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=1e4,M=1e6;
int n,m,k;
struct Node{
    int u,v,w;
    bool operator < (const Node &rhs)const {
        return w<rhs.w;
	}
}a[M],b[15];
int p[N],ans,c[15];
int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}
void build(){
    for(int i=1;i<=m;i++){
        int u=a[i].u,v=a[i].v;
        if(find(u)==find(v))continue;
        else{
            p[find(v)]=find(u);
            ans+=a[i].w;
        }
    }
    return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=m+1;i<=m+k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>b
        }
    }
    sort(a+1,a+m+1);
    iota(p+1,p+n+k+1,1);
    build();
    cout<<ans;
	return 0;
}
