#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p+=a[i];
    }
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(n-(j-i+1)>=3){
                int cnt=p,cnt1=0;
                for(int k=i;k<=j;k++){
                    cnt-=a[k];
                }
                if(j!=n){
                    cnt1=a[n];
                }
                else{
                    cnt1=a[i-1];
                }
                if(cnt>=2*cnt1){
                    ans++;
                }
            }
        }
    }
        int cnt=p,cnt1=0;
        cnt-=a[1];
        cnt-=a[n];
        cnt1=a[n-1];
        if(cnt>=2*cnt1){
            ans++;
        }
    cout<<ans;
    return 0;
}

