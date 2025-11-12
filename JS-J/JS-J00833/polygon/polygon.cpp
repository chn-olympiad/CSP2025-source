#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5e5;
short a[N];
void suun(int b){
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    sort(a+1,a+b+1);
    if(a[1]+a[2]>a[3]){
        cout<<"1";
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n<=3){
        suun(n);
    }else{
        long long sum=0,maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
    }
    return 0;
}
