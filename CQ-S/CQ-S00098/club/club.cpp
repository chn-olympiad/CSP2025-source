#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn][5],num[5];
vector<int>g[5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ll sum=0;
        for(int i=1;i<=3;i++)num[i]=0,g[i].clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            int mx=0,k=0,cur=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(mx<a[i][j]){
                    mx=a[i][j];
                    k=j;
                }
            }
            num[k]++;
            sum+=(ll)mx;
            for(int j=1;j<=3;j++){
                if(j!=k)cur=max(cur,a[i][j]);
            }
            g[k].push_back(mx-cur);
        }
        int h=0;
        for(int i=1;i<=3;i++)h=max(h,num[i]);
        if(h<=n/2){
            cout<<sum<<"\n";
            continue;
        }
        for(int i=1;i<=3;i++){
            if(h==num[i]){
                sort(g[i].begin(),g[i].end());
                for(int j=0;j<h-n/2;j++)sum-=(ll)g[i][j];
                break;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
/*
3
4
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