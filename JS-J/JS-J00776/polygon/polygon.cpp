#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    if(n<=2) cout<<cnt<<endl;
    if(n==3){
        int sum=0;
        int maxt=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(maxt<=a[i]) maxt=a[i];
        }
        if(sum>maxt*2) cnt++;
        cout<<cnt<<endl;
    }else{
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        if(sum==n){
            for(int i=1;i<=n-2;i++) cnt+=i;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
