#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[105];
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
    int ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==ans){
            cnt=i;
            break;
        }
        cout<<a[i]<<" ";
    }
    cout<<ans<<endl;
    if(cnt/m%2==0){
        cout<<cnt/m+1<<" "<<cnt%n;

    }else{
        cout<<cnt/m+1<<" "<<n-(cnt-1)%n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
