#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c=1;
    cin>>n>>m;
    int a[n*m+10];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        }
    for(int j=1;j<n*m;j++){
        if(a[j]>a[0])c++;
        }
    int x=c/n,y;
    if(x%2==0 && c%n==0)y=1;
    else if(x%2!=0 && c%n==0)y=n;
    else if(x%2==0 && c%n!=0){
        x=x+1;
        y=c%n;
        }
    else if(x%2!=0 && c%n!=0){
        x=x+1;
        y=n-c%n+1;
        }
    cout<<x<<' '<<y;
    return 0;
    }
