#include <bits/stdc++.h>
#define int long long
const int N=1000086;
using namespace std;
struct mm{
    int a,b,c,maxx,pos;
}f[N];
int s[N][5];
int t,n,ans=0,x,y,z,pos=0;
int dp[N];
bool cmp1(mm x,mm y){
    return x.maxx>y.maxx;
}
bool cmp2(int x,int y){
    return x>y;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int kk=1;kk<=t;kk++){
        cin>>n;
        f[0].a=0;
        f[0].b=0;
        f[0].c=0;
        x=0;
        y=0;
        z=0;
        for(int i=1;i<=n;i++){
            cin>>s[i][1]>>s[i][2]>>s[i][3];
            f[i].a=s[i][1];
            f[i].b=s[i][2];
            f[i].c=s[i][3];
        }

        for(int i=1;i<=n;i++){
            if(s[i][2]!=0||s[i][3]!=0) pos++;
        }
        if(pos==0){
            for(int i=1;i<=n;i++){
                dp[i]=s[i][1];
            }
            sort(dp+1,dp+n+1,cmp2);
            for(int i=1;i<=n/2;i++){
                ans+=dp[i];
            }
            cout<<ans;
            return 0;
        }
        for(int i=1;i<=n;i++){
            f[i].maxx=max(max(f[i].a,f[i].b),max(f[i].b,f[i].c));
            if(f[i].maxx==f[i].a){
                f[i].pos=1;
            }
            if(f[i].maxx==f[i].b){
                f[i].pos=2;
            }
            if(f[i].maxx==f[i].c){
                f[i].pos=3;
            }
        }
        sort(f+1,f+n+1,cmp1);
        for(int i=n-1;i>=0;i--){
            if(f[i].pos==1){
                x++;
                if(x>n/2){
                    for(int j=i;j>=1;j--) f[j].a=0;
                    f[i].maxx=max(f[i].c,f[i].b);
                    if(f[i].maxx==f[i].b){
                        f[i].pos=2;
                    }
                    if(f[i].maxx==f[i].c){
                        f[i].pos=3;
                    }
                }
                f[i].a+=f[i+1].maxx;
                f[i].b+=f[i+1].maxx;
                f[i].c+=f[i+1].maxx;
                f[i].maxx=max(max(f[i].a,f[i].b),max(f[i].b,f[i].c));
                if(f[i].maxx==f[i].a){
                    f[i].pos=1;
                }
                if(f[i].maxx==f[i].b){
                    f[i].pos=2;
                }
                if(f[i].maxx==f[i].c){
                    f[i].pos=3;
                }
                continue;
            }
            if(f[i].pos==2){
                y++;
                if(y>n/2){
                    for(int j=i;j>=1;j--) f[j].b=0;
                    f[i].maxx=max(f[i].c,f[i].a);
                    if(f[i].maxx==f[i].c){
                        f[i].pos=3;
                    }
                    if(f[i].maxx==f[i].a){
                        f[i].pos=1;
                    }
                }
                f[i].a+=f[i+1].maxx;
                f[i].b+=f[i+1].maxx;
                f[i].c+=f[i+1].maxx;
                f[i].maxx=max(max(f[i].a,f[i].b),max(f[i].b,f[i].c));
                if(f[i].maxx==f[i].a){
                    f[i].pos=1;
                }
                if(f[i].maxx==f[i].b){
                    f[i].pos=2;
                }
                if(f[i].maxx==f[i].c){
                    f[i].pos=3;
                }
                continue;
            }
            if(f[i].pos==3){
                z++;
                if(z>n/2){
                    for(int j=i;j>=1;j--) f[j].c=0;
                    f[i].maxx=max(f[i].b,f[i].a);
                    if(f[i].maxx==f[i].b){
                        f[i].pos=2;
                    }
                    if(f[i].maxx==f[i].a){
                        f[i].pos=1;
                    }
                }
                f[i].a+=f[i+1].maxx;
                f[i].b+=f[i+1].maxx;
                f[i].c+=f[i+1].maxx;
                f[i].maxx=max(max(f[i].a,f[i].b),max(f[i].b,f[i].c));
                if(f[i].maxx==f[i].a){
                    f[i].pos=1;
                }
                if(f[i].maxx==f[i].b){
                    f[i].pos=2;
                }
                if(f[i].maxx==f[i].c){
                    f[i].pos=3;
                }
                continue;
            }
        }
        cout<<f[1].maxx<<"\n";
    }

    return 0;

}






























/*signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int kk=1;kk<=t;kk++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        opp(1,1,1,n);
        cout<<ans<<"\n";
        ans=0;
    }


    return 0;


}
//4 2 1
//3 2 4
//5 3 4
//3 5 1

*/
