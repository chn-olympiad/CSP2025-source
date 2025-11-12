#include<bits/stdc++.h>
using namespace std;
int n,maxn,sum,cnt;
int a[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        sum+=a[i];
    }
        if(sum>maxn*2){
            cnt++;
        }
        cout<<cnt;
    return 0;

}
