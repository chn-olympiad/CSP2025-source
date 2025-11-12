#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1];
    int num=0;
    sort(a+1,a+1+n*m,cmp);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            num++;
            if(a[num]==s){
                int l=(num%n==0?num/n:num/n+1);
                int h=(l%2==0?(n%2==0?n-j+1:n-j):j);
                cout<<l<<" "<<h;

            }
        }
    }
    return 0;
}
