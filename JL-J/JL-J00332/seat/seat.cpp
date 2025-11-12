#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,cnt=0,b,c=1,r=1;
    int a[101]={0};
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+100,cmp);
    for (int i=1;i<=100;i++){
        if (a[i]==b){
            cnt=i;
        }
    }
    c=int((double(cnt)/double(n))+0.9999);
    if (c%2==0){
        r=n-(cnt%n)+1;
        if (cnt%n==0){
            r=1;
        }
    }

    else{
        r=cnt%n;
    }
    if (r==0){
        r=n;
    }
    cout<<c<<" "<<r;
    return 0;
}
