#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        int cnt=3;
        while(cnt<=i){
            int sum=0;
            for(int j=i-cnt+1;j<=i;j++){
                sum+=a[j];
            }
            if(sum>a[i]*2){
                s++;
                s%=998244353;
            }
            cnt++;
        }
    }
    cout<<s;

    return 0;
}
