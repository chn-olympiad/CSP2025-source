#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,s[100010][4],mx[100010],secmx[100010];
struct node{
    int val,id;
    bool operator <(const node o)const{
        return val>o.val;
    }
};
priority_queue<node> qu[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        ans=0;
        for(int i=0;i<=2;i++){
            while(!qu[i].empty()){
                qu[i].pop();
            }
        }
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            mx[i]=secmx[i]=3;
            s[i][3]=LLONG_MIN;
            for(int j=0;j<=2;j++){
                scanf("%lld",&s[i][j]);
                if(s[i][j]>s[i][mx[i]]){
                    secmx[i]=mx[i];
                    mx[i]=j;
                }
                else{
                    if(s[i][j]>s[i][secmx[i]]){
                        secmx[i]=j;
                    }
                }
            }
            qu[mx[i]].push((node){s[i][mx[i]]-s[i][secmx[i]],i});
            ans+=s[i][mx[i]];
        }
        for(int i=0;i<=2;i++){
            while(qu[i].size()>n/2){
                node qtop=qu[i].top();
                qu[i].pop();
                ans-=qtop.val;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
