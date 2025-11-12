#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int top;
int a[100010];
int mp[101][101];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    //for(int i=1;i<=n*m;i++){
    //    cout<<a[i]<<" ";
    //}
    //cout<<endl;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                mp[i][j]=a[++top];
                if(mp[i][j]==r){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                mp[i][j]=a[++top];
                if(mp[i][j]==r){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=m;j++){
    //        cout<<mp[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    return 0;
}
