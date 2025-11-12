#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
    int minc;
}a[1000001];
bool cmp(node x,node y){
    return x.minc>y.minc;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t--){
        int n;cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].minc=max({a[i].x,a[i].y,a[i].z}) - min({a[i].x,a[i].y,a[i].z});
        }
        long long my=0;
        int la=n/2;
        int lb=n/2;
        int lc=n/2;
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++){
            int maxn=max({a[i].x,a[i].y,a[i].z});
            if (maxn==a[i].x){
                if (la>0){
                    my+=a[i].x;
                    la--;
                }
                else if(la<=0){
                    maxn=max(a[i].y,a[i].z);
                    if (maxn==a[i].y){
                        if (lb>0){
                            my+=a[i].y;
                            lb--;
                        }
                        else if (lb<=0){
                            my+=a[i].z;
                        }
                    }
                }
            }
            else if(maxn==a[i].y){
                if (lb>0){
                    my+=a[i].y;
                    lb--;
                }
                else if(lb<=0){
                    maxn=max(a[i].x,a[i].z);
                    if (maxn==a[i].x){
                        if (la>0){
                            my+=a[i].x;
                            la--;
                        }
                        else if (la<=0){
                            my+=a[i].z;
                        }
                    }
                }
            }
            else {
                my+=a[i].z;
            }
        }
        cout<<my<<endl;
    }
    return 0;
}
