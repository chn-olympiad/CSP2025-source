#include<bits/stdc++.h>
using namespace std;
int n,m,c,h;
int a[110],ans[20][20];
bool cmp(int x,int y){
    if(x>=y){
        return true;
    }
    return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    c=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;){
        for(int j=1;j<=n && j>=1;){
            if(i%2==1){
                ans[i][j]=a[++h];
                if(ans[i][j]==c){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                if(j==n){
                    i++;
                }else{
                    j++;
                }
            }else{
                ans[i][j]=a[++h];
                if(ans[i][j]==c){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                if(j==1){
                    i++;
                }else{
                    j--;
                }
            }
        }
    }
    return 0;
}
