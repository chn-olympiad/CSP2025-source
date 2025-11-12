#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
int a[105],f[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int ans,ansi,ansj;
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            ans=i;
            break;
        }
    }
    int cnt=0;
    for(int j=1;j<=m;j++){
        if(j%2!=0){
            for(int i=1;i<=n;i++){
                cnt++;
                if(cnt==ans){
                    ansi=i;
                    ansj=j;
                    break;
                }
            }
        }
        else{
            for(int i=n;i>=1;i--){
                cnt++;
                if(cnt==ans){
                    ansi=i;
                    ansj=j;
                    break;
                }
            }
        }
    }
    cout<<ansj<<" "<<ansi;
    return 0;
}