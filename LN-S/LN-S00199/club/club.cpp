#include<bits/stdc++.h>
using namespace std;
struct stu{
    int a;
    int b;
    int c;
    int imax;

}x[100001];
int n;
void init(int n){
    for(int i=1;i<=n;i++){
        x[i].a=0;
        x[i].b=0;
        x[i].c=0;
        x[i].imax=0;
    }
    return;
}
bool cmp(stu a,stu b){
    if(a.imax>b.imax){
        return true;
    }
    else{
        return false;
    }
}
int bans=0,zans=0;
void dfs(int a,int b,int c,int d){
    if(a>n/2||b>n/2||c>n/2){
        return;
    }
    else if(a+b+c==n){
        zans=max(zans,bans);
        return;
    }
    for(int i=a+b+c+1;i<=n;i++){
        bans+=x[i].a;
        dfs(a+1,b,c,d+x[i].a);
        bans-=x[i].a;
        bans+=x[i].b;
        dfs(a,b+1,c,d+x[i].b);
        bans-=x[i].b;
        bans+=x[i].c;
        dfs(a,b,c+1,d+x[i].c);
        bans-=x[i].c;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int T;
    cin>>T;
    int as,bs,cs,ans,hb=0,hc=0;
    while(T--){
        as=0;
        bs=0;
        cs=0;
        ans=0;
        cin>>n;
        init(n);
        for(int i=1;i<=n;i++){
            cin>>x[i].a>>x[i].b>>x[i].c;
            if(x[i].a>=x[i].b&&x[i].a>=x[i].c){
                x[i].imax=x[i].a;
                as++;
            }
            else if(x[i].b>=x[i].a&&x[i].b>=x[i].c){
                x[i].imax=x[i].b;
                bs++;
            }
            else if(x[i].c>=x[i].a&&x[i].c>=x[i].a){
                x[i].imax=x[i].c;
                cs++;
            }
            hb+=x[i].b;
            hc+=x[i].c;
        }
        if(as<=n/2&&bs<=n/2&&cs<=n/2){
            for(int i=1;i<=n;i++){
                ans+=x[i].imax;
            }
            cout<<ans<<endl;
            continue;
        }
        else if(hb==0&&hc==0){
            sort(x+1,x+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=x[i].imax;
            }
            cout<<ans<<endl;
            continue;
        }
        else if(n<=30){
            dfs(0,0,0,1);
            cout<<zans<<endl;
        }
        else{
            int la=0;
            int lb=0;
            int lc=0;
            for(int i=1;i<=n;i++){
                if(x[i].imax==x[i].a){
                    if(la<n/2){
                        ans+=x[i].a;
                        la++;
                    }
                    else{
                        if(x[i].b>x[i].c){
                            if(lb<n/2){
                                ans+=x[i].b;
                                lb++;
                            }
                            else{
                                ans+=x[i].c;
                                lc++;
                            }
                        }
                        else{
                            if(lc<n/2){
                                ans+=x[i].c;
                                lc++;
                            }
                            else{
                                ans+=x[i].b;
                                lb++;
                            }
                        }
                    }

                }
                else if(x[i].imax==x[i].b){
                    if(lb<n/2){
                        ans+=x[i].b;
                        lb++;
                    }
                    else{
                        if(x[i].a>x[i].c){
                            if(la<n/2){
                                ans+=x[i].a;
                                la++;
                            }
                            else{
                                ans+=x[i].c;
                                lc++;
                            }
                        }
                        else{
                            if(lc<n/2){
                                ans+=x[i].c;
                                lc++;
                            }
                            else{
                                ans+=x[i].a;
                                la++;
                            }
                        }
                    }

                }
                else if(x[i].imax==x[i].c){
                    if(lc<n/2){
                        ans+=x[i].c;
                        lc++;
                    }
                    else{
                        if(x[i].b>x[i].a){
                            if(la<n/2){
                                ans+=x[i].a;
                                la++;
                            }
                            else{
                                ans+=x[i].a;
                                la++;
                            }
                        }
                        else{
                            if(la<n/2){
                                ans+=x[i].a;
                                la++;
                            }
                            else{
                                ans+=x[i].b;
                                lb++;
                            }
                        }
                    }

                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
