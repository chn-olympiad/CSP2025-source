#include<bits/stdc++.h>
using namespace std;
long long m,n,d,f,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<m*n;i++)
        for(int j=0;j<=m*n-1-i;j++)
            if(a[j+1]>a[j]){
            d=a[j];
            a[j]=a[j+1];
            a[j+i]=d;
            if(f==j)f++;
            else if(f==j+1)f--;
            }
    f++;
    c=(f-1)/n%2;
    if(c==1){
        r=f%n;
    }else{
       r=n-f%n;
    }
    cout<<c<<r;

    return 0;
}

