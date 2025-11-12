#include<bits/stdc++.h>
using namespace std;
int s[15][15],n,m,sc[225];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>sc[i];
    int st=sc[1],cnt=1;
    sort(sc+1,sc+1+n*m,greater<int>());
    for(int i=1;i<=m;i++){
        if(i&1)
        {
            for(int j=1;j<=n;j++){
                s[j][i]=sc[cnt++];
            }
        }
        else
        {
            for(int j=n;j>=1;j--){
                s[j][i]=sc[cnt++];
            }
        }
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(s[j][i]==st){cout<<i<<' '<<j;return 0;}
}
