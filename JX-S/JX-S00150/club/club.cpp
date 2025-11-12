#include<bits/stdc++.h>
using namespace std;
int a[100005][4],b[4],k[100005];
int main(){
    freopen("club5.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        int ans=0;
        b[1]=b[2]=b[3]=0;
        for(int i=1;i<=n;i++){
            int p=0;
            for(int j=1;j<=3;j++)
                if(a[i][j]>a[i][p])
                    p=j;
            ans+=a[i][p];
            b[p]++;
        }
        int op=0;
        for(int i=1;i<=3;i++)
            if(b[i]>n/2)
                op=i;
        if(op){
            int cnt=0;
            for(int i=1;i<=n;i++){
                int p=0,pp=0;
                for(int j=1;j<=3;j++)
                    if(a[i][j]>a[i][p])
                        p=j;
                for(int j=1;j<=3;j++)
                    if(j!=p&&a[i][j]>a[i][pp])
                        pp=j;
                if(p==op)
                    k[++cnt]=a[i][p]-a[i][pp];
            }
            sort(k+1,k+cnt+1);
            for(int i=1;i<=b[op]-n/2;i++)
                ans-=k[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
