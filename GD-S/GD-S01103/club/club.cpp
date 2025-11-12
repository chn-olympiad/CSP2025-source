#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
char Begin;
int read(){
    int num=0;
    char ch;ch=getchar();
    while(ch<48||ch>57)ch=getchar();
    while(ch>47&&ch<58){
        num=(num<<1)+(num<<3)+(ch^48);
        ch=getchar();
    }return num;
}
ll min(ll x,ll y){return x<y?x:y;}
ll max(ll x,ll y){return x>y?x:y;}
const int N=1e5+15;
ll a[N],b[N],c[N];
ll ans;
int n,id[N],s[5];
std::vector<ll>d[5];
void work(){
    n=read(),ans=0;
    fr(i,1,3)s[i]=0,d[i].clear();;
    fr(i,1,n){
        a[i]=read(),b[i]=read(),c[i]=read();
        ans+=max(max(a[i],b[i]),c[i]);
        if(a[i]>=b[i]&&a[i]>=c[i]){id[i]=1;continue;}
        if(b[i]>=c[i]){id[i]=2;continue;}
        id[i]=3;
    }
    fr(i,1,n){
        s[id[i]]++;
        if(id[i]==1)d[1].push_back(max(b[i],c[i])-a[i]);
        if(id[i]==2)d[2].push_back(max(a[i],c[i])-b[i]);
        if(id[i]==3)d[3].push_back(max(b[i],a[i])-c[i]);
    }
    fr(i,1,3){
        std::stable_sort(d[i].begin(),d[i].end());
        while(s[i]>n/2){
            ans+=d[i].back();
            d[i].pop_back();
            s[i]--;
        }
    }
    printf("%lld\n",ans);
}
char End;
int main(){
    // std::cerr<<(&End-&Begin)/1024/1024<<std::endl;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int Case=read();
    while(Case--)work();
}