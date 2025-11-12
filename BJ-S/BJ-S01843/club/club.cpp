#include <bits/stdc++.h>

using namespace std;


int n,t,ans,dp[100010],a[100010][4],b[100010],cnt[4];

struct node{
    int val,link;
};
node c[4],delta[4][100010];

bool cmp(node a1,node a2){
    return a1.val>a2.val;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        bool f2=1,f3=1,f1=1;
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]!=0) f1=0;
            if(a[i][2]!=0) f2=0;
            if(a[i][3]!=0) f3=0;
            for(int j=1;j<=3;j++){
                c[j].link=j;
                c[j].val=a[i][j];
            }
            sort(c+1,c+n+1,cmp);
            ans+=c[1].val;
            cnt[c[1].link]++;
            dp[i]=c[1].link;
        }


        if(f2 and f3){
            ans=0;
            for(int i=1;i<=n;i++) b[i]=a[i][1];
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2+1;i--){
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        }else if(f1 and f3){
            ans=0;
            for(int i=1;i<=n;i++) b[i]=a[i][2];
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2+1;i--){
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        }else if(f2 and f1){
            ans=0;
            for(int i=1;i<=n;i++) b[i]=a[i][3];
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2+1;i--){
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        }else{
            int to=0,der;
            for(int i=1;i<=3;i++){
                if(cnt[i]>n/2) to=i,der=cnt[i]-n/2;
            }
            if(to==0){
                cout<<ans<<endl;
                continue;
            }
            else{
                for(int i=1;i<=3;i++){
                    if(i==to) continue;
                    for(int j=1;j<=n;j++){
                        if(dp[j]!=i) delta[i][j].val=a[j][i]-a[j][to];
                        else delta[i][j].val=-20010;
                    }
                    sort(delta[i]+1,delta[i]+n+1,cmp);
                }
                if(to==3){
                    for(int i=1;i<=der;i++){
                        b[i]=delta[1][i].val;
                        b[der+i]=delta[2][i].val;
                    }
                }
                if(to==2){
                    for(int i=1;i<=der;i++){
                        b[i]=delta[1][i].val;
                        b[der+i]=delta[3][i].val;
                    }
                }
                if(to==1){
                    for(int i=1;i<=der;i++){
                        b[i]=delta[3][i].val;
                        b[der+i]=delta[2][i].val;
                    }
                }
                sort(b+1,b+2*der+1);
                for(int i=2*der;i>=der+1;i--){
                    ans+=b[i];
                }
                cout<<ans<<endl;
            }
        }

    }
    return 0;
}
