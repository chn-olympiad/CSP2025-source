#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[110];
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int b=a[1];
    int d;
    int c,r;
    for(int i=1;i<m*n;i++){
        for(int j=1;j<m*n;j++){
            if(a[j]<a[j+1]){
                d=a[j];
                a[j]=a[j+1];
                a[j+1]=d;
            }
        }
    }
    for(int i=1;i<=m*n;i++){
        if(a[i]==b){
            b=i;
            break;
        }
    }
    if(b%n==0){
        c=b/n;
    }else{
        c=b/n+1;
    }
    if(c%2==0){
        r=(n+1)-(b-n*(c-1));
    }else{
        r=(b-n*(c-1));
    }
    cout<<c<<" "<<r;
}
