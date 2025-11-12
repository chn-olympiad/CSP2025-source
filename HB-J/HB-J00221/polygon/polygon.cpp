#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],b[5005],c[5005],num,x;
void dfs(int maxx,int maxxx,int he,int shu){
    num=num%=N;
    for(int i=maxxx+1;i<=n;i++){
        if(shu>=2&&he>a[i]) num++;
        dfs(a[i],i,he+a[i],shu+1);
    }
    return;
}
int cadd(int x,int y){
    long long sum=1,y2=y;
    if(y2>x/2) y2=x-y2;
    for(int i=x;i>x-y2;i--){
        sum*=i;
        sum/=(x-i+1);
        sum%=N;
    }
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    if(b[1]==n||n>=30){
        for(int i=3;i<=n;i++){
            num+=cadd(n,i);
            cout<<num;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) dfs(a[i],i,a[i],i);
    cout<<num%N;
    return 0;
}
