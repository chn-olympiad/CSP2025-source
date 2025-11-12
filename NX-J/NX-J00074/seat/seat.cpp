#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s,ans[110][110];
    cin>>n>>m;
    int a[110];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            s=a[i];
        }
    }
    int cnt=0;
    sort(a+1,a+n*m+1);
    int j=1;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            j=n;
            while(j>=1){
                ans[i][j]=a[n*m-cnt];
                if(ans[i][j]==s){
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
                j--;
            }
        }else if(i%2!=0&&i>1){
            while(j<=n){
                j++;
                ans[i][j]=a[n*m-cnt];
                if(ans[i][j]==s){
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
            }
        }
        if(i==1){
            while(j<=n){
                ans[i][j]=a[n*m-cnt];
                if(ans[i][j]==s){
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
                j++;
            }
        }
    }
}
