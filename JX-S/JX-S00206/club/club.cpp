#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct asdf{
    int fi,se,th;
}a[1000010];
int flA(asdf x,asdf y){
    return x.fi>y.fi;
}
int cmp(asdf x,asdf y){
    int sum1=x.fi+x.se+x.th;
    int sum2=y.fi+y.se+y.th;
    return sum1<sum2;
}
int cmp1(asdf x,asdf y){
    int sum1=x.fi+x.se+x.th;
    int sum2=y.fi+y.se+y.th;
    return sum1>sum2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        bool flagA=1,flagB=1;
        cin>>n;
        int ans=0;
        int a1=n/2,a2=n/2,a3=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].fi>>a[i].se>>a[i].th;
            if(a[i].se!=0) flagA=0;
            if(a[i].th!=0) flagA=flagB=0;
        }
        if(flagA){
            sort(a+1,a+1+n,flA);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].fi;
            }
            cout<<ans;
            continue;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].fi>a[i].se&&a[i].fi>a[i].th){
                if(!a1){
                    if(!a3){
                        ans+=a[i].se;
                        a2--;
                    }
                    if(!a2){
                        ans+=a[i].th;
                        a3--;
                    }
                    if(a[i].se>a[i].th&&a2){
                        ans+=a[i].se;
                        a2--;
                    }else{
                        ans+=a[i].th;
                        a3--;
                    }
                }else{
                    ans+=a[i].fi;
                    a1--;
                }
            }else if(a[i].se>a[i].fi&&a[i].se>a[i].th){
                if(!a2){
                    if(!a3){
                        ans+=a[i].fi;
                        a1--;
                    }
                    if(!a1){
                        ans+=a[i].th;
                        a3--;
                    }
                    if(a[i].fi>a[i].th&&a1){
                        ans+=a[i].fi;
                        a1--;
                    }else{
                        ans+=a[i].th;
                        a3--;
                    }
                }else{
                    ans+=a[i].se;
                    a2--;
                }
            }else{
                if(!a3){
                    if(!a2){
                        ans+=a[i].fi;
                        a1--;
                    }
                    if(!a1){
                        ans+=a[i].se;
                        a2--;
                    }
                    if(a[i].fi>a[i].se&&a1){
                        ans+=a[i].fi;
                        a1--;
                    }else{
                        ans+=a[i].se;
                        a3--;
                    }
                }else{
                    ans+=a[i].th;
                    a3--;
                }
            }
        }
        int sum=0;
        a1=n/2,a2=n/2,a3=n/2;
        sort(a+1,a+1+n,cmp1);
        for(int i=1;i<=n;i++){
            if(a[i].fi>a[i].se&&a[i].fi>a[i].th){
                if(!a1){
                    if(!a3){
                        sum+=a[i].se;
                        a2--;
                    }
                    if(!a2){
                        sum+=a[i].th;
                        a3--;
                    }
                    if(a[i].se>a[i].th&&a2){
                        sum+=a[i].se;
                        a2--;
                    }else{
                        sum+=a[i].th;
                        a3--;
                    }
                }else{
                    sum+=a[i].fi;
                    a1--;
                }
            }else if(a[i].se>a[i].fi&&a[i].se>a[i].th){
                if(!a2){
                    if(!a3){
                        sum+=a[i].fi;
                        a1--;
                    }
                    if(!a1){
                        sum+=a[i].th;
                        a3--;
                    }
                    if(a[i].fi>a[i].th&&a1){
                        sum+=a[i].fi;
                        a1--;
                    }else{
                        sum+=a[i].th;
                        a3--;
                    }
                }else{
                    sum+=a[i].se;
                    a2--;
                }
            }else{
                if(!a3){
                    if(!a2){
                        sum+=a[i].fi;
                        a1--;
                    }
                    if(!a1){
                        sum+=a[i].se;
                        a2--;
                    }
                    if(a[i].fi>a[i].se&&a1){
                        sum+=a[i].fi;
                        a1--;
                    }else{
                        sum+=a[i].se;
                        a3--;
                    }
                }else{
                    sum+=a[i].th;
                    a3--;
                }
            }
        }
        ans=max(sum,ans);
        cout<<ans<<endl;
    }
    return 0;
}
// i never love ccf T_T
// 100 -> 0
// dp code deleted
// nooooooooooooooooooooooooooooooooooo
// tot 100+20+40+8=168/
// tot 100->20/0+20+40+8=88/68

