#include<bits/stdc++.h>
using namespace std;

struct adds{
    int num;
    int f,s,r;
    int use,p;
};adds a[10005];

struct lcdp{
    int num,feel;
};lcdp yx[10005];
int all;

bool cmp1(adds x,adds y){
    return x.f>y.f;
}
bool cmp2(adds x,adds y){
    return x.s>y.s;
}
bool cmp3(adds x,adds y){
    return x.r>y.r;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,cut=0,ans=0;
    int x;
    cin>>t;
    for(int k=1;k<=t;++k){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            a[i].num=i;a[i].use=0;a[i].p=0;
            yx[i].feel=0;yx[i].num=0;
            for(int j=1;j<=3;++j){
                cin>>x;
                if(j==1){
                    a[i].f=x;
                }else if(j==2){
                    a[i].s=x;
                }else if(j==3){
                    a[i].r=x;
                }
            }
        }

        cut=0;
        //First
        sort(a+1,a+n,cmp1);
        for(int i=1;i<=n;++i){
            if(all!=n){
                for(int j=1;j<=n;++j){
                    if(yx[i].num=0){
                        yx[i].feel=a[j].f;
                        yx[i].num=a[j].num;
                        a[j].use++;
                        cut++;
                        a[j].p=i;
                        all++;
                    }
                }
            }
            for(int j=1;j<=n;++j){
                if(cut==n/2) break;
                if(a[j].use==0){
                    if(a[j].f>yx[i].feel){
                        yx[i].feel=a[j].f;
                        yx[i].num=a[j].num;
                        a[j].use++;
                        cut++;
                        a[j].p=i;
                    }
                }else{
                    if(a[j].f>yx[i].feel && a[j].f>yx[a[j].p].feel){
                        yx[a[j].p].num=0;yx[a[j].p].feel=0;
                        yx[i].feel=a[j].f;
                        yx[i].num=a[j].num;
                        cut++;
                        a[j].p=i;
                    }
                }
            }
        }
        cut=0;
        //look second club's student
        sort(a+1,a+n,cmp2);
        for(int i=1;i<=n;++i){
           if(all!=n){
                for(int j=1;j<=n;++j){
                    if(yx[i].num=0){
                        yx[i].feel=a[j].s;
                        yx[i].num=a[j].num;
                        a[j].use++;
                        cut++;
                        a[j].p=i;
                        all++;
                    }
                }
            }
            for(int j=1;j<=n;++j){
                if(cut==n/2) break;
                if(a[j].use==0){
                    if(a[j].s>yx[i].feel){
                        yx[i].feel=a[j].s;
                        yx[i].num=a[j].num;
                        a[j].use++;
                        cut++;
                        a[j].p=i;
                    }
                }else{
                    if(a[j].s>yx[i].feel && a[j].s>yx[a[j].p].feel){
                        yx[a[j].p].num=0;yx[a[j].p].feel=0;
                        yx[i].feel=a[j].s;
                        yx[i].num=a[j].num;
                        cut++;
                        a[j].p=i;
                    }
                }
            }

        }
        cut=0;
        //Third
        sort(a+1,a+n,cmp3);
        for(int i=1;i<=n;++i){
            if(all!=n){
                for(int j=1;j<=n;++j){
                    if(yx[i].num=0){
                        yx[i].feel=a[j].r;
                        yx[i].num=a[j].num;
                        a[j].use++;
                        cut++;
                        a[j].p=i;
                        all++;
                    }
                }
            }
            for(int j=1;j<=n;++j){
                if(cut==n/2) break;
                if(a[j].use==0){
                    if(a[j].r>yx[i].feel){
                        yx[i].feel=a[j].r;
                        yx[i].num=a[j].num;
                        a[j].use++;
                        cut++;
                        a[j].p=i;
                    }
                }else{

                    if(a[j].r>yx[i].feel && a[j].r>yx[a[j].p].feel){
                        yx[a[j].p].num=0;yx[a[j].p].feel=0;
                        a[j].p=i;
                        yx[i].feel=a[j].r;
                        yx[i].num=a[j].num;
                        cut++;
                    }
                }
            }
        }

        for(int i=1;i<=n;++i){
            ans+=yx[i].feel;
        }
        cout<<ans<<endl;
    }
    return 0;
}
