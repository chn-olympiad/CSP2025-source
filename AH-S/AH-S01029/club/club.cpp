#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100005],b[100005],c[100005];
int tmp[100005],ans,sum[100005],cnta,cntb;
void dfs(int x,int sa,int sb,int sc,int s){
    if(s+sum[n]-sum[x-1]<=ans) return ;
    if(x>n){
        ans=max(ans,s);
        return ;
    }
    if(sa+1<=n/2) dfs(x+1,sa+1,sb,sc,s+a[x]);
    if(sb+1<=n/2) dfs(x+1,sa,sb+1,sc,s+b[x]);
    if(sc+1<=n/2) dfs(x+1,sa,sb,sc+1,s+c[x]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool fa=true,fb=true;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            sum[i]=sum[i-1]+max(max(a[i],b[i]),c[i]);
            if(b[i]!=0) fa=false;
            if(c[i]!=0) fb=false,fa=false;
        }
        if(fa){
            //cout<<1<<endl;
            sort(a+1,a+n+1);
            for(int i=n/2+1;i<=n;i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
            ans=0;
            continue;
        }
        if(fb){
            //cout<<1<<endl;
            for(int i=1;i<=n;i++){
                if(a[i]>b[i]){
                    cnta++;
                    ans+=a[i];
                }else if(a[i]<b[i]){
                    ans+=b[i];
                    cntb++;
                }else{
                    ans+=a[i];
                }
                tmp[abs(a[i]-b[i])]++;
            }
            if(cnta>n/2){
                int d=cnta-n/2;
                //cout<<d<<endl;
                for(int i=1;i<=20000;i++){
                    if(d<=0) break;
                    if(tmp[i]>0){
                        if(d>=tmp[i]){
                            ans-=i*tmp[i];
                            d-=tmp[i];
                        }else{
                            ans-=d*i;
                            d=0;
                        }
                    }
                }
            }else if(cntb>n/2){
                int d=cntb-n/2;
                //cout<<d<<endl;
                for(int i=1;i<=20000;i++){
                    if(d<=0) break;
                    if(tmp[i]>0){
                        if(d>tmp[i]){
                            d-=tmp[i];
                            ans-=i*tmp[i];
                        }else{
                            ans-=d*i;
                            d=0;
                        }
                    }
                }
            }
            /*
            for(int i=0;i<=20000;i++){
                cout<<tmp[i]<<" ";
            }
            */
            cout<<ans<<endl;
            ans=0;
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
