#include<bits/stdc++.h>
using namespace std;

string s,ans;
int a[105],n,m,R;

int get1(int x){
    int i=x%n,j=(x%n==0?(x-1)/n+1:x/n+1);
    if(j%2!=0) return (i==0?n:i);
    else return (i==0?1:n+1-i);
}

int get2(int x){
    return (x%n==0?(x-1)/n+1:x/n+1);
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
        if(i==1) R=a[1];
    }
    sort(a+1,a+n*m,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R) {cout<<get2(i)<<" "<<get1(i);return 0;}
    }
    return 0;
}
