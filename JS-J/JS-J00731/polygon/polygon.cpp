#include<bits/stdc++.h>
using namespace std;
long long n,a[100001][2],s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
        a[i][0]+=a[i-1][0];
        a[i][1]=max(a[i][0],a[i-1][1]);
    }
    int l=1,r=4;
    while(l<=r-3&&r<=n){
        if(a[r][0]-a[l][0]>a[r][1]){
            s++;
            l++;
        }else{
            r++;
        }
    }
    cout<<s%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
