#include<bits/stdc++.h>
using namespace std;
long long n,minx,cnt,a[5005]={0};
bool cmp(int x,int y){
    return (x>y);
}
int sumint(int x,int y){
    int sum;
    for(int i=x;i<=y;i++){
        sum+=a[i];
    }
    return sum;
}
int f(int x,int y,int sum){
    if(sumint(x,y)>a[x]*2&&y-x+1>=3) return (1+f(x,y-1,0))%998244353;
    if(sumint(x,y)>a[x]*2) return 1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(minx=0;minx<n;minx++){
        cnt+=f(minx,n,0);
    }
    cout<<cnt%998244353;
    return 0;
}
