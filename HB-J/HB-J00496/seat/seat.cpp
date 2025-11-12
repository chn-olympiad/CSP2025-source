#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[200];
bool cmp(int f,int g){
    return f>g;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int grade=a[1];
    int x=0;
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++){
        if (grade==a[i]){
            x=i;
            break;
        }
    }
    int p=(x/(2*n))*2;
    int q=0;
    if (x%(2*n)==0){
        q=1;
    }
    else if(x%(2*n)>n){
        p+=2;
        q=n-(x%(n*2)-n)+1;
    }
    else if(x%(2*n)<=n){
        p+=1;
        q=x%(2*n);
    }
    cout<<p<<" "<<q;
    return 0;
}
