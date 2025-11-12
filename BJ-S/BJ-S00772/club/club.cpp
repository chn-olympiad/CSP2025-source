#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000000000000000ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rep_(i,a,b) for(int i=(a);i<(b);i++)
#define per_(i,a,b) for(int i=(a);i>(b);i--)
#define N 100001
int n,a[N][3],c[3];
void mian(int argt){
    cin>>n;
    rep(i,1,n){
        rep(j,0,2){
            cin>>a[i][j];
        }
    }
    int ans=0;
    rep(i,0,2){
        int sum=0;
        memset(c,0,sizeof(c));
        rep(j,1,n){
            int t=i;
            rep(k,0,2){
                if(a[j][k]>a[j][t]){
                    t=k;
                }
            }
            c[t]++;
            sum+=a[j][t];
        }
        bool flag=0;
        rep(j,0,2){
            if(j==i){
                continue;
            }
            if(c[j]>(n>>1)){
                flag=1;
            }
        }
        if(flag){
            continue;
        }
        if(c[i]>(n>>1)){
            priority_queue<int>q;
            rep(j,1,n){
                int t=i;
                rep(k,0,2){
                    if(a[j][k]>a[j][t]){
                        t=k;
                    }
                }
                if(t==i){
                    int mx=-1,mi;
                    rep(k,0,2){
                        if(i==k){
                            continue;
                        }
                        if(a[j][k]>=mx){
                            mx=a[j][k];
                            mi=k;
                        }
                    }
                    q.push(mx-a[j][i]);
                }
            }
            while(c[i]>(n>>1)){
                sum+=q.top();
                q.pop();
                c[i]--;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=1;
    cin>>T;
    rep(i,1,T){
        mian(i);
    }
}
