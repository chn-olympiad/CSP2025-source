#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5010;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int j=a[1]+a[2];
        j+=a[3];
        sort(a+1,a+4);
        if(j>2*a[3]){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        return 0;
    }
    long long cnt=0;
    sort(a+1,a+n+1);
    long long  c=0;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            c=(a[j]+a[j+i-1])*i/2;
            if(c>(a[j+i-1]*2)){
                cnt++;

            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}
