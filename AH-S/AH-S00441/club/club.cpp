#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100005][5],c[5],d[100005];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        c[1]=c[2]=c[3]=0;
        for(int i=1;i<=n;i++){
            int id=1,mx=-1;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>mx){
                    mx=a[i][j];
                    id=j;
                }
            }
            ans+=mx;
            c[id]++,d[i]=id;
        }
        if(c[1]>n/2){
            priority_queue<int,vector<int>,greater<int> > q;
            for(int i=1;i<=n;i++){
                if(d[i]==1){
                    int mx=-1,id=2;
                    for(int j=2;j<=3;j++){
                        if(a[i][j]>mx){
                            mx=a[i][j];
                            id=j;
                        }
                    }
                    q.push(a[i][d[i]]-mx);
                }
            }
            while(c[1]>n/2){
                c[1]--;
                ans-=q.top();
                q.pop();
            }
        }else if(c[2]>n/2){
            priority_queue<int,vector<int>,greater<int> > q;
            for(int i=1;i<=n;i++){
                if(d[i]==2){
                    int mx=-1,id=2;
                    for(int j=1;j<=3;j++){
                        if(j==2) continue;
                        if(a[i][j]>mx){
                            mx=a[i][j];
                            id=j;
                        }
                    }
                    q.push(a[i][d[i]]-mx);
                }
            }
            while(c[2]>n/2){
                c[2]--;
                ans-=q.top();
                q.pop();
            }
        }else if(c[3]>n/2){
            priority_queue<int,vector<int>,greater<int> > q;
            for(int i=1;i<=n;i++){
                if(d[i]==3){
                    int mx=-1,id=2;
                    for(int j=1;j<=2;j++){
                        if(a[i][j]>mx){
                            mx=a[i][j];
                            id=j;
                        }
                    }
                    q.push(a[i][d[i]]-mx);
                }
            }
            while(c[3]>n/2){
                c[3]--;
                ans-=q.top();
                q.pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
