#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int c=0,x=1;
    char ch=getchar();

    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            x=-1;
        }
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c*x;
}

int n,a[100005][3];
int maxlove[100005],midlove[100005],down[100005];
int x[3],u;
int down1[100005];

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T=read();
    while(T--){
        n=read();
        x[0]=0,x[1]=0,x[2]=0;

        for(int i=1;i<=n;i++){
            a[i][0]=read(),a[i][1]=read(),a[i][2]=read();

            if(a[i][0]>=a[i][1]&&a[i][1]>=a[i][2]){
                maxlove[i]=0,midlove[i]=1;
            }
            if(a[i][0]>=a[i][2]&&a[i][2]>=a[i][1]){
                maxlove[i]=0,midlove[i]=2;
            }
            if(a[i][1]>=a[i][0]&&a[i][0]>=a[i][2]){
                maxlove[i]=1,midlove[i]=0;
            }
            if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][0]){
                maxlove[i]=1,midlove[i]=2;
            }
            if(a[i][2]>=a[i][0]&&a[i][0]>=a[i][1]){
                maxlove[i]=2,midlove[i]=0;
            }
            if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][0]){
                maxlove[i]=2,midlove[i]=1;
            }

            x[maxlove[i]]++;
            down[i]=a[i][maxlove[i]]-a[i][midlove[i]];
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i][maxlove[i]];
        }

        int maxnum=max(x[0],max(x[1],x[2])),cnt=0;

        if(maxnum>n/2){
            if(maxnum==x[0]){
                u=0;
            }
            if(maxnum==x[1]){
                u=1;
            }
            if(maxnum==x[2]){
                u=2;
            }

            for(int i=1;i<=n;i++){
                if(maxlove[i]==u){
                    cnt++;
                    down1[cnt]=down[i];
                }
            }

            sort(down1+1,down1+cnt+1);
            for(int i=1;i<=maxnum-n/2;i++){
                ans-=down1[i];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
