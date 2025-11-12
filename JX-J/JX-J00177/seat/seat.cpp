#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int l,int r){
    return l>r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    int s1=a[1];
    sort(a+1,a+k+1,cmp);

    for(int i=1;i<=k;i++){
        if(a[i]==s1) s1=i;
    }

    int c=s1/n+s1%n,r;

    int s=s1/n;
    if(s%2==0) {
        if(s1%n==0)
            r=1;
        else
            r=s1%n;
    }

    else{
        if(s1%n==0)
            r=n;
        else
            r=n-s1%n+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
