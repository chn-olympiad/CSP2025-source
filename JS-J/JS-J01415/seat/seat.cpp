#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],s[110],c,r,l,t;
bool cmp(int q,int w){
    return q>w;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>s[i];
    l=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(s[++t]==l){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        if(i%2==0){
            for(int j=m;j>=1;j--){
                if(s[++t]==l){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
