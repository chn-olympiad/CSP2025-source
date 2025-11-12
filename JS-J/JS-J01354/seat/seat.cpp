#include<bits/stdc++.h>
using namespace std;
#define please return
#define AC 0
int n,m,s[105],x,k[12][12],y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>s[i];
    x=s[0];
    sort(s,s+n*m);
    for(int i=0;i<m;i+=2){
        for(int j=0;j<n;j++){
            k[j][i]=s[n*m-y];
            y++;
        }
        if(i+1<m){
            for(int j=n-1;j>=0;j--){
                k[j][i+1]=s[n*m-y];
                y++;
            }
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(k[i][j]==x)cout<<j+1<<" "<<i+1;
    please AC;
}
