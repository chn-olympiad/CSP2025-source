#include <bits/stdc++.h>
using namespace std;
struct member{
    int a1,a2,a3,f,c,maxn,f2,g;
};
member cl[100010];
bool cmp(member a,member b){
    if (a.c!=b.c){
        return a.c>b.c;
    }
    return a.maxn>b.maxn;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,ans=0;
    cin>>t;
    while (t--){
        int fir=0,sec=0,thi=0;
        ans=0;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>cl[i].a1>>cl[i].a2>>cl[i].a3;
            cl[i].maxn=max(cl[i].a1,max(cl[i].a2,cl[i].a3));
            if (cl[i].maxn==cl[i].a1){
                cl[i].f=1;
                cl[i].f2=max(cl[i].a2,cl[i].a3);
                if (cl[i].f2==cl[i].a2){
                    cl[i].g=2;
                }else{
                    cl[i].g=3;
                }
            }else if (cl[i].maxn==cl[i].a2){
                cl[i].f=2;
                cl[i].f2=max(cl[i].a1,cl[i].a3);
                if (cl[i].f2==cl[i].a1){
                    cl[i].g=1;
                }else{
                    cl[i].g=3;
                }
            }else{
                cl[i].f=3;
                cl[i].f2=max(cl[i].a2,cl[i].a1);
                if (cl[i].f2==cl[i].a2){
                    cl[i].g=2;
                }else{
                    cl[i].g=1;
                }
            }
            cl[i].c=cl[i].maxn-cl[i].f2;
        }
        sort(cl+1,cl+n+1,cmp);
        for (int i=1;i<=n;i++){
            if (cl[i].f==1){
                if (fir<n/2){
                    fir++;
                    ans+=cl[i].a1;
                }else{
                    if (cl[i].g==2){
                        if (sec<n/2){
                            sec++;
                            ans+=cl[i].a2;
                        }else{
                            thi++;
                            ans+=cl[i].a3;
                        }
                    }
                }
            }
            if (cl[i].f==2){
                if (sec<n/2){
                    sec++;
                    ans+=cl[i].a2;
                }else{
                    if (cl[i].g==1){
                        if (fir<n/2){
                            fir++;
                            ans+=cl[i].a1;
                        }else{
                            thi++;
                            ans+=cl[i].a3;
                        }
                    }
                }
            }
            if (cl[i].f==3){
                if (thi<n/2){
                    thi++;
                    ans+=cl[i].a3;

                }else{
                    if (cl[i].g==2){
                        if (sec<n/2){
                            sec++;
                            ans+=cl[i].a2;
                        }else{
                            fir++;
                            ans+=cl[i].a1;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
