#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x;
    int y;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            x=a[i];
        }
    }
    for(int i=0;i<n*m;i++){
        sort(a,a+m*n,cmp);
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==x){
            y=i;
        }
    }
    cout<<floor(y/n)+1<<' ';
    int z=floor(y/n)+1;
    if(n%2==1){
        cout<<y%n+1;
    }
    else
        cout<<m-y%n;

    return 0;
}

