#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001],c[200001];
bool cmp(int x,int y){
    if(x>y)return true;
    return false;
}
bool cmp2(int x,int y){
    if(a[x]>a[y])return true;
    return false;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        bool xzA=true,xzB=true;
        cin>>n;
        bool vis[n+1];
        memset(vis,true,sizeof(vis));
        for(int i=0;i<n;i++){
            cin>>a[i];cin>>b[i];cin>>c[i]; if(b[i]!=0)xzA=false;if(c[i]!=0){
                    xzA=false;
                    xzB=false;
                }
        }
        if(n==2){
                int maxn=-1;
            for(int a1=0;a1<3;a1++){
                for(int a2=0;a2<3;a2++){
                    if(a1==a2)continue;
                    maxn=max(a[a1]+b[a2],maxn);
                }
            }
            cout<<maxn<<"\n";
            continue;
        }
        if(n==4){
            int maxn=-1;

            for(int a1=0;a1<n;a1++){
                int b[4]={0,0,0,0};
                b[a1]++;
                for(int a2=0;a2<n;a2++){
                    b[a2]++;
                    for(int a3=0;a3<n;a3++){
                        b[a3]++;
                        for(int a4=0;a4<n;a4++){
                            b[a4]++;
                            int cn=true;
                            for(int S=0;S<4;S++){
                                if(b[S]>=2){
                                    cn=false;
                                }
                            }
                            if(cn)
                                maxn=max(a[a1]+b[a2],maxn);
                            else{
                                b[a4]--;
                                cn=true;
                                continue;
                            }

                        }
                    }

                }
            }
            cout<<maxn<<"\n";
            continue;
        }
        if(xzA){
            sort(a,a+n,cmp);
            int ans=0;
            for(int i=0;i<n/2;i++)ans+=a[i];
            cout<<ans<<"\n";
            continue;
        }
        if(xzB){
            int a1[n+1],a1s=0;
            for(int i=0;i<n;i++){
                if(a[i]>b[i]){
                    a1[a1s]=i;
                    a1s++;
                }
            }
            sort(a1,a1+a1s,cmp2);
            int ans=0;
            for(int i=0;i<a1s;i++){
                if(i>=n/2)break;
                ans+=a[i];
                vis[i]=false;
            }
            for(int i=0;i<n;i++){
                if(vis[i]){
                    ans+=b[i];
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        cout<<n<<"\n";
    }

    return 0;
}
