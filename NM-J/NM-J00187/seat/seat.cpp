#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int n,m;
    cin>>n>>m;
    int x;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    int sum=0;
    sort(a,a+n*m);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x) sum=i;
    }
    int c=0,r=0;
    if(sum%n==0){
        c=sum/n;
        r=n;
    }
    else{
        c=sum/n+1;
        r=sum%n;
    }
    cout<<c<<' '<<r;
    return 0;
}

