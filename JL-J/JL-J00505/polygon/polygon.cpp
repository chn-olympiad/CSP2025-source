#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int u=0;
    for(int k=3;k<=n;k++){
        int maxn=0,cnt=0;;
        for(int i=1;i<=k;i++){
            maxn=max(maxn,a[i]);
            cnt+=a[i];
        }
        if(cnt>2*maxn)u++;
    }
    cout<<u<<endl;
    return 0;
}
