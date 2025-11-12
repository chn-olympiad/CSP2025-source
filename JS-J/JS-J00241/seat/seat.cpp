#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,m,a[15][15],f,cnt=1,ans;
struct node{
    int s,p;
}x[105];
bool cmp(node a,node b){
    return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    f=n*m;
    for(int i=1;i<=f;i++){
        cin>>x[i].s;
        x[i].p=i;
    }
    sort(x+1,x+f+1,cmp);
    for(int i=1;i<=f;i++)   if(x[i].p==1)   ans=i;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(cnt==ans){
                    cout<<i<<' '<<j;
                    return 0;
                }
                a[i][j]=cnt;
                cnt++;
            }
        }
        else{
            for(int j=m;j>=1;j--){
                if(cnt==ans){
                    cout<<i<<' '<<j;
                    return 0;
                }
                a[i][j]=cnt;
                cnt++;
            }
        }
    }
    return 0;
}
