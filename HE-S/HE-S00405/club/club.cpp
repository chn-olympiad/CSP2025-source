#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100005],ans=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        f=3;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
        }
        sort(a[1]+1,a[1]+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[1][i];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
