#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    int v=a[0];
    int u;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++)
        if(a[i]==v)u=i;
    if((u/n)%2==1){
        if(u%n==0)cout<<n<<' ';
        else cout<<u%n<<' ';
        if(u/n==0)cout<<n;
        else cout<<(u+(n-u%n))/n;
    }
    else{
        if(u/n!=0)cout<<(u+(n-u%n))/n<<' ';
        else cout<<1<<' ';
        if(u%n!=0)cout<<n-(u%n)+1;
        else cout<<1;
    }
    return 0;
}
