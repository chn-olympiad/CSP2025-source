#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
    int maxn,midn,minn;
}a[100005];
bool my_cmp(node x,node y){
    if(x.maxn-x.midn!=y.maxn-y.midn) return x.maxn-x.midn>y.maxn-y.midn;
    else if(x.midn-x.minn!=y.midn-y.minn) return x.midn-x.minn>y.midn-y.minn;
    else if(x.minn!=y.minn) return x.minn>y.minn;
    else return x.minn+1>y.minn;
}
int p[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            p[1]=a[i].x,p[2]=a[i].y,p[3]=a[i].z;
            sort(p+1,p+4);
            a[i].minn=p[1],a[i].midn=p[2],a[i].maxn=p[3];
        }
        int pl=n/2;
        sort(a+1,a+n+1,my_cmp);
        long long ans=0,cntx=0,cnty=0,cntz=0;
        for(int i=1;i<=n;i++){
            if(a[i].x==a[i].maxn){
                if(cntx<pl){
                    ans+=a[i].x;
                    cntx++;
                }else{
                    if(a[i].y==a[i].midn){
                        if(cnty<pl){
                            ans+=a[i].y;
                            cnty++;
                        }else{
                            ans+=a[i].z;
                            cntz++;
                        }
                    }else{
                        if(cntz<pl){
                            ans+=a[i].z;
                            cntz++;
                        }else{
                            ans+=a[i].y;
                            cnty++;
                        }
                    }
                }
            }else if(a[i].y==a[i].maxn){
                if(cnty<pl){
                    ans+=a[i].y;
                    cnty++;
                }else{
                    if(a[i].x==a[i].midn){
                        if(cntx<pl){
                            ans+=a[i].x;
                            cntx++;
                        }else{
                            ans+=a[i].z;
                            cntz++;
                        }
                    }else{
                        if(cntz<pl){
                            ans+=a[i].z;
                            cntz++;
                        }else{
                            ans+=a[i].x;
                            cntx++;
                        }
                    }
            }
        }else{
            if(cntz<pl){
                ans+=a[i].z;
                cntz++;
            }else{
                if(a[i].x==a[i].midn){
                    if(cntx<pl){
                        ans+=a[i].x;
                        cntx++;
                    }else{
                        ans+=a[i].z;
                        cntz++;
                    }
                }else{
                    if(cnty<pl){
                        ans+=a[i].y;
                        cnty++;
                    }else{
                        ans+=a[i].y;
                        cnty++;
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
    }
    return 0;
}
