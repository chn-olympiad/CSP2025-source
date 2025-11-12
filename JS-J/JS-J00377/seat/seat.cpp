#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],v=1,bs;
int qiulie(){
    if(v%n==0)return (v/n);
    else return (v/n+1);
}
int qiuhang(){
    int d=v%(2*n);
    if(d==1 || d==0)return 1;
    else if(d==2 || d==(2*n-2+1))return 2;
    else if(d==3 || d==(2*n-3+1))return 3;
    else if(d==4 || d==(2*n-4+1))return 4;
    else if(d==5 || d==(2*n-5+1))return 5;
    else if(d==6 || d==(2*n-6+1))return 6;
    else if(d==7 || d==(2*n-7+1))return 7;
    else if(d==8 || d==(2*n-8+1))return 8;
    else if(d==9 || d==(2*n-9+1))return 9;
    else return 10;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    bs=a[1];
    if(n<=1 && m<=1)cout<<1<<" "<<1;
    else{
        sort(a+1,a+n*m+1);
        for(int i=n*m;i>=1;i--){
            if(bs==a[i])break;
            v++;
        }
        cout<<qiulie()<<" ";
        cout<<qiuhang();
    }
    return 0;
}
