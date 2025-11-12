#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(inr i=r;i>=l;i--)
const int N=1e5+5;
int T,n,a[N][3],c[3],tmp[N];
vector<int>e;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        int rs=0;
        fo(t,0,2)
            c[t]=0;
        fo(i,1,n){
            int mx=0,id=0;
            fo(j,0,2){
                cin>>a[i][j];
                if (a[i][j]>mx)
                    mx=a[i][j],id=j;
            }
            rs+=mx,c[id]++;
            tmp[i]=id;
        }
        bool flag=0;
        fo(t,0,2)
            flag|=(c[t]*2>n);
        if (!flag){
            cout<<rs<<'\n';
            continue;
        }
        int s=0,id=0;
        fo(t,0,2)
            if (c[t]*2>n)
                s+=c[t]-(n/2),id=t;
        e.clear();
        fo(i,1,n){
            if (tmp[i]!=id)
                continue;
            int mx=0;
            fo(j,0,2)
                if (j!=id)
                    mx=max(mx,a[i][j]);
            e.push_back(a[i][id]-mx);
        }
        sort(e.begin(),e.end());
        fo(i,0,s-1)
            rs-=e[i];
        cout<<rs<<'\n';
    }
    return 0;
}
/*
剑旗爵，是我赢了。

凯撒，恕我直言，我没有看出您为什么赢了。
*/