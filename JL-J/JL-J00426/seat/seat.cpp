//身不比，男儿列；心却比，男儿烈
//我man的
//c++学不会这一块不缺人才/ovo/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool comp1(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    int d=1;
    sort(a+1,a+1+n*m,comp1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t)d=i;
    }
    int c,r;
    if(d%n!=0)
        c=d/n+1;
    else c=d/n;
    if(c%2!=0){
        r=d%n;
        if(r==0)r=n;
    }
    else{
        r=n-d+n*(c-1)+1;
        if(r==1)r=n;
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
