#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define ull unsigned long long
//#define int long long
using namespace std;
const int N=1e4+11;
int n;
struct club{
    int a1,a2,a3;
}a[N];
void solve(){
    scanf("%d",&n);
    if(n==2){
       int x[4];
        int y[4];
        int mx=-1e9,f,num;
        int ans;
        scanf("%d%d%d%d%d%d",x+1,x+2,x+3,y+1,y+2,y+3);
        rep(i,1,3){
			if(mx<x[i]){
				mx=x[i];
				num=i;
				f=1;
			}
			if(mx<x[i]){
				mx=y[i];
				num=i;
				f=2;
			}
        }int mx2=-1*1e9;
        rep(i,1,3){
			if(i==num)continue;
			if(f!=1){
				mx2=max(mx2,x[i]);
			}else{
			mx2=max(mx2,y[i]);
			}
		}
		ans=mx+mx2;
        printf("%d\n",ans);
        return;
    }
    bool flag3=1,flag2=1;
    rep(i,1,n){
        scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
        if(a[i].a2!=0){
            flag2=0;
        }
        if(a[i].a3!=0){
            flag3=0;
        }
    }
    if(flag2==1&&flag3==1){
            int ans=0;
        rep(i,1,n){
            ans=max(ans,a[i].a1);
        }
    printf("%d\n",ans);
    return;
    }
        int ans=0;
        int fg=0,mx=0;//,cc;
        rep(i,1,n){
            if(mx<a[i].a1){
                mx=a[i].a1;
                //cc=i;
                fg=1;
            }
            if(mx<a[i].a2){
                mx=a[i].a2;//cc=i;
                fg=2;
            }
            if(mx<a[i].a3){
                mx=a[i].a3;//cc=i;
                fg=3;
            }
        }
        int fg2=0,mx2=0;//,cc2;
        rep(i,1,n){
            if(fg!=1){
            if(mx2<a[i].a1){
                mx2=a[i].a1;
                //cc2=i;
                fg2=1;
            }}
            if(fg!=2){
            if(mx2<a[i].a2){
                mx2=a[i].a2;//cc2=i;
                fg2=2;
            }}
            if(fg!=3){
            if(mx2<a[i].a3){
                mx2=a[i].a3;//cc2=i;
                fg2=3;
            }
            }
        }
        bool tong[4];
        rep(i,0,3)tong[i]=0;
        int f;
        tong[fg]=1;
        tong[fg2]=1;
        rep(i,1,3){
            if(tong[i]==0){f=i;break;}
        }
        int mx3=0;
        rep(i,1,n){
            if(f==1){
            if(mx3<a[i].a1){
                mx3=a[i].a1;
                //cc3=i;
                //fg3=1;
            }}
            if(f==2){
            if(mx3<a[i].a2){
                mx3=a[i].a2;//cc3=i;
                //fg3=2;
            }}
            if(f==3){
            if(mx3<a[i].a3){
                mx3=a[i].a3;//cc3=i;
                //fg3=3;
            }
            }
        }
        ans=mx+mx2+mx3;
        printf("%d\n",ans);
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}

