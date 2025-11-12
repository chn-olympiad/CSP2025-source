#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define getchar getchar_unlocked
#define putchar putchar_unlocked
namespace stdio_promax{
	inline void read(int& x){x=0;int f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}x*=f;}
	inline void read(ll& x){x=0;int f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}x*=f;}
	inline void write(int x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10^48);}
	inline void write(ll x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10^48);}
}
using namespace stdio_promax;
const int N=1e5+10;
int T,n;
struct node{
    int m[3],id[3],now;
    bool operator<(const node tw)const{
        return m[id[now]]-m[id[now+1]]>tw.m[tw.id[tw.now]]-tw.m[tw.id[tw.now+1]];
    }
};
priority_queue<node>q[3];
void deal(node& a){
    if(a.m[0]>=a.m[1]&&a.m[0]>=a.m[2]){
        a.id[0]=0;
        if(a.m[1]>=a.m[2])a.id[1]=1,a.id[2]=2;
        else a.id[1]=2,a.id[2]=1;
    }else if(a.m[1]>=a.m[2]){
        a.id[0]=1;
        if(a.m[0]>=a.m[2])a.id[1]=0,a.id[2]=2;
        else a.id[1]=2,a.id[2]=0;
    }else{
        a.id[0]=2;
        if(a.m[0]>=a.m[1])a.id[1]=0,a.id[2]=1;
        else a.id[1]=1,a.id[2]=0;
    }
    a.now=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    read(T);
    while(T--){
        read(n);
        for(int i=0;i<3;i++)while(!q[i].empty())q[i].pop();
        int limit[3]={0,0,0};
        int ans=0;
        node tw;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                read(tw.m[j]);
            }
            deal(tw);
            int now=tw.id[tw.now];
            ans+=tw.m[now];
            limit[now]++;
            q[now].push(tw);
            if(limit[now]>n/2){
                limit[now]--;
                node yw=q[now].top();
                q[now].pop();
                ans-=yw.m[yw.id[yw.now]]-yw.m[yw.id[yw.now+1]];
                yw.now++;
                q[yw.id[yw.now]].push(yw);
                limit[yw.id[yw.now]]++;
            }
        }
        write(ans);
        putchar('\n');
    }
	return 0;
}
