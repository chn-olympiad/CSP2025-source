#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,s1,s,g,c,r,a[10005];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n;
    cin>>m;
    cin>>s1;
    a[0]=s1;
    for(int i=1;i<n*m;i++){
        cin>>s;
        a[i]=s;
    }
    sort(a+1,a+n*m+1);
    for(int i=0;i<n*m;i++){
        if(a[i]==s1);
        g=i;
    }
    c=g/n;
    if(g>c*n) c++;
    if(c%2==0) r=n-g%n;
    else if(c%2==1) r=g-(c-1)*n;
    cout<<c<<" "<<r;
    return 0;
}
