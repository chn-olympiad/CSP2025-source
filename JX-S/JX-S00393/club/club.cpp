#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define db long double
#define F(i,k,n) for (int i=k;i<=n;i++)
#define R(i,k,n) for (int i=k;i>=n;i--)
#define ins insert
#define mpr make_pair
#define pu push_back
#define mes(a,b) memset(a,b,sizeof a);
//2326968
const int N=1e5+10;
int T,n;
int a[N][4];
int sum[4];
int l[N];
vector<int>vec;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        vec.clear();
        mes(sum,0);
        F(i,1,n){
            F(j,1,3) cin>>a[i][j];
        }
        int ans=0;
        F(i,1,n){
            int mx=max(a[i][1],max(a[i][2],a[i][3]));
            if (mx==a[i][1]){
                sum[1]++;l[i]=1;
            }
            else if (mx==a[i][2]) sum[2]++,l[i]=2;
            else sum[3]++,l[i]=3;
            ans+=mx;
        }
        int pn;
        int g=0;
        F(i,1,3){
            if (sum[i]>(n/2)){
                g=sum[i]-(n/2);
                F(j,1,n){
                    if (l[j]==i){
                        pn=0;
                        F(k,1,3) if (k!=i) pn=max(pn,a[j][k]);
                        vec.pu(a[j][i]-pn);
                    }
                }
                break;
            }
        }
        sort(vec.begin(),vec.end());
        F(i,0,g-1) ans-=vec[i];
        cout<<ans<<'\n';
    }
    return 0;
}
/*
3 4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/