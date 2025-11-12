#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
//#define int long long int
long long int ans;
int n, a[N][4], m=-1, cnt, T;
int x[N], y[N], z[N], sum[4], minn[N];
bool cmp(int a, int b){
    return a < b;
}
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    cin>>T;
    while(T--){
        ans=cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
                if(a[i][2]>=a[i][3]){x[i]=1;y[i]=2;z[i]=3;}
                else{x[i]=1;y[i]=3;z[i]=2;}
            }else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
                if(a[i][1]>=a[i][3]){x[i]=2;y[i]=1;z[i]=3;}
                else{x[i]=2;y[i]=3;z[i]=1;}
            }else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
                if(a[i][1]>=a[i][2]){x[i]=3;y[i]=1;z[i]=1;}
                else{x[i]=3;y[i]=2;z[i]=1;}
            }
            ans+=a[i][x[i]];
            sum[x[i]]++;
        }
        m=-1;
        for(int i=1;i<=3;i++)if(sum[i]>(n/2))m=i;
        //cout<<m<< "\n" ;
        if(m==-1){cout<<ans<< "\n" ;}
        else{
            for(int i=1;i<=n;i++){
                if(x[i]!=m)continue;
                minn[++cnt]=a[i][x[i]]-a[i][y[i]];
            }
            sort(minn+1, minn+1+cnt, cmp);
            for(int i=1;i<=sum[m]-(n/2);i++)ans-=minn[i];
            cout<<ans<< "\n" ;
        }
        memset(minn,0,sizeof(minn));
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
    }

    return 0;
}
