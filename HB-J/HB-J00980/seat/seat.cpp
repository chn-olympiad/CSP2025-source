#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[105],b[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        b[i]=a[i];
    }
    for(int i=1;i<=n*m;i++){
        a[n*m-i+1]=b[i];
    }
    int xb;
    for(int i=1;i<=n*m;i++){
        if(r==a[i]){
            xb=i;
        }
    }
    int x=xb/n;
    int y=xb%n;
    if(y!=0){
        x++;
        if(x%2==0){
            cout<<x<< " " <<n-y+1;
        }
        else{
            cout<<x<< " " <<y;
        }
    }
    else{
        if(x%2==0){
            cout<<x<< " " <<1;
        }
        else{
            cout<<x<< " " <<n;
        }
    }
    return 0;
}
/*
2 2
97 99 100 98
*/
