#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[24];int tot=0;
	do{stk[++tot]=x%10+48;x/=10;}while(x);
	for(;tot;)putchar(stk[tot--]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
const int maxn=1e5+4;int T,n,a[maxn][3],cnt[3],ans;std::basic_string<int>E[3];
std::vector<std::pair<int,int> >G;bool vis[maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
    for(;T--;){
        read(n);cnt[0]=cnt[1]=cnt[2]=0;E[0].clear();E[1].clear();E[2].clear();
        G.clear();ans=0;
        for(int i=1;i<=n;++i){
            read(a[i][0],a[i][1],a[i][2]);vis[i]=0;
            int maxx=std::max({a[i][0],a[i][1],a[i][2]});ans+=maxx;
            if(maxx==a[i][0])cnt[0]++,E[0]+=i;
            else if(maxx==a[i][1])cnt[1]++,E[1]+=i;
            else cnt[2]++,E[2]+=i;
        }
        int op=-1;
        if(cnt[0]>n/2)op=0;
        if(cnt[1]>n/2)op=1;
        if(cnt[2]>n/2)op=2;
        if(op!=-1){
            for(int x:E[op]){
                if(op!=0)G.emplace_back(std::make_pair(a[x][op]-a[x][0],x));
                if(op!=1)G.emplace_back(std::make_pair(a[x][op]-a[x][1],x));
                if(op!=2)G.emplace_back(std::make_pair(a[x][op]-a[x][2],x));
            }
            std::sort(G.begin(),G.end());
            int mx=0;
            for(auto[val,x]:G){
                if(!vis[x]){
                    vis[x]=1;
                    ans-=val;
                    mx++;
                }
                if(cnt[op]-mx<=n/2)break;
            }
        }
        write(ans,'\n');
    }
	return 0;
}