#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],b[maxn],k,num;
int sum=0;
void f(int x,int cnt,int deep,int sum1){
    if(deep>num)return;
    for(int i=cnt;i<=x;i++){
        if(a[i]+sum1<k){
            sum++;
            sum%=998244353;
            f(x,i+1,deep+1,sum1+a[i]);
        }
        else return;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<n;i++){
        if(b[i]<=a[i+1]||i-2<0)continue;
        k=b[i]-a[i+1];
        num=i-2;
        sum++;
        f(i,1,1,0);
    }
    cout<<sum;
    return 0;
}
