#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
int n,m,t;
int a[N];
int f(int t){
    int l=1,r=n*m+1;
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]>t)r=mid;
        else if(a[mid]<t)l=mid;
        return mid;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n+1);
    int h=f(t);
    int x=h/n+1;
    int y=(h+1)%n;
    printf("%d %d",y,x);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
