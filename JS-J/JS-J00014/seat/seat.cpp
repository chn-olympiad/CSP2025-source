#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=15,M=150;
int n,m,a[M],tot,s[N][N];
set<int,greater<int>>st;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",a+i),st.insert(a[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            s[j][i]=++tot;
        }
        i++;
        for(int j=n;j>=1;j--){
            s[j][i]=++tot;
        }
    }
    //for(int i:st){
    //    cout<<i<<" ";
    //}cout<<'\n';
    int cnt=0;
    while(*st.begin()!=a[1]){
       st.erase(*st.begin()),cnt++;
    }
    cnt++;
    //cout<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==cnt){
                cout<<j<<" "<<i<<'\n',exit(0);
            }
        }
    }
    return 0;
}
