#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s[101],mp[105][105];
    int u=n*m;
    for(int i=1;i<=u;i++)cin>>s[i];
    int me=s[1];
    sort(s+1,s+1+u);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            mp[j][i]=s[u];
            u--;
        }
        i++;
        if(i>m)break;
        for(int j=n;j>=1;j--){
            mp[j][i]=s[u];
            u--;
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(mp[j][i]==me){
                cout<<i<<" "<<j;
                return 0;
            }
}
