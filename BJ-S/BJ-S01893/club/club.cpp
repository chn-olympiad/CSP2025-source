#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int t,n,lans=0;
int a[N][4];
int aa[N];
struct node {
    int num,cho;
}b[N];
int cn[3];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--) {
        memset(a,0,sizeof(a));
        memset(cn,0,sizeof(cn));
        cin>>n;
        bool flag=0,flag2=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=3;j++){
            cin>>a[i][j];
            aa[i]=a[i][1];
            if(a[i][2]!=0||a[i][3]!=0) flag=1;
            if(a[i][3]!=0) flag2=1;
        }


        sort(aa+1,aa+n+1);
        if(!flag) {
            int ans=0;
            for(int i=1;i<=n/2;i++) {
                ans+=aa[i];
            }
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++) {
            int x=max(max(a[i][1],a[i][2]),a[i][3]);
            if(a[i][1]==x) {
                b[i].cho=1;
            }
            else if(x==a[i][2]) {
                b[i].cho=2;
            }
            else if(x==a[i][3]) {
                b[i].cho=3;
            }
            b[i].num=max(max(a[i][1],a[i][2]),a[i][3]);
            if(cn[b[i].cho]>=n/2) {
                cn[b[i].cho]--;
                int lch;
                for(int j=1;j<=3;j++) {
                    if(j==b[i-1].cho) continue;
                    if(b[i-1].num+a[i][j]>b[i].num) {
                        b[i].num=b[i-1].num+a[i][j];
                        lch=j;
                    }
                }
                b[i-1].cho=lch;
                cn[b[i].cho]=cn[b[i].cho]++;
            }
            else {
                cn[b[i].cho]=cn[b[i].cho]+1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            ans+=a[i][b[i].cho];
            //cout<<b[i].cho<<" ";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
