#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
bool check(int b){

    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    int f[10]={0,0,0,0,0,0,0,0,0,0};
    while(b){
        if(a%10==0)return 0;
        if(f[b%10]==0){
            f[b%10]=1;
        }
        else return 0;
    }
    for(int i=9;i>=1;i--){
        if(f[i]==1){
            if(a[i]*2<sum)return 1;
        }
    }
}
long long n,a[5005],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int f=pow(10,n);
    for(int i=123;i<=f;i++){
        if(check(i))cnt++;
    }
    cout<<cnt;
}
