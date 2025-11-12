#include<bits/stdc++.h>
using namespace std;
long long n,m,tmp;
long long a[105];
long long x,y;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    tmp=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==tmp){
            tmp=i;
        }
    }
    x=(tmp/n)+1;
    if(x%2==1){
        y=tmp%n;
    }else{
        y=n+1-tmp%n;
    }
    cout<<x<<" "<<y;
    return 0;
}
