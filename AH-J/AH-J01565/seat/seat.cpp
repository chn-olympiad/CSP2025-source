#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int pos,x;
int a[105];
string s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            pos=a[i];
        }
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==pos){
            x=i;
        }
    }
    x=m*n-x+1;
    //cout<<x<<" ";
    cout<<(x-1)/n+1<<" ";
    int s=x%n;
    if(s==0){
        s=n;
    }
    if(((x-1)/n+1)%2==1){
        cout<<s;
    }else{
        cout<<n-s+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
x
{
(x-1)/n+1
}

y
{
if((x/n)%2==1) n-x%n+1
else           x%n-1
}
*/






