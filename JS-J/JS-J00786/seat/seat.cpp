#include<bits/stdc++.h>
using namespace std;
int mp[101][101];
int a[10111];
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int t=1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                mp[i][j]=a[t];
                t++;
                if(mp[i][j]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                mp[i][j]=a[t];
                t++;
                if(mp[i][j]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;

}
