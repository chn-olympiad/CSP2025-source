#include <bits/stdc++.h>
#define N 11
using namespace std;
int n,m,num,cnt,ans,num1,cnt1;
bool flag =true;
int a[101];
int b[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cnt=n*m,cnt1=n;
    for(int i=1;i<=cnt;i++){
        cin>>a[i];
    }
    num = a[1];
    sort(a+1,a+cnt+1);
    for(int i=1;i<=cnt;i++){
        if(a[i]==num){
            ans = i;
        }
    }
    for(int i=1;i<=m;i++){
        if(flag == false){
            for(int j =n;j>=1;j--){
                b[j][i]=cnt;
                cnt--;
            }
            flag = true;
        }else{
            for(int j = 1;j<=n;j++){
                b[j][i]=cnt;
                cnt--;
            }
            flag = false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==ans){
                cout<<j<<" "<<i;
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

