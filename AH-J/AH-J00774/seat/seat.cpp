#include<bits/stdc++.h>
using namespace std;
int a[205];
int t[205][205];
bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a+1,a+1+sum,cmp);

        int cnt=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                t[i][j]=a[cnt];
                cnt++;
            }

        }else{
            for(int j=n;j>=1;j--){
                t[i][j]=a[cnt];
                cnt++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(t[i][j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }

        }else{
            for(int j=n;j>=1;j--){
                if(t[i][j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }

            }
        }
    }
    return 0;
}
