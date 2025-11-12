#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0;
long long a=0,b=0,u=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>u;
    for(int i = 1;i<n*m;i++){
        cin>>a;
        if(a>u)b++;
    }
    cout<<b/n+1<<" ";
    int e = b/n+1,d = b%m+1;
    if(e%2){
        cout<<d;
    }else{
        cout<<m-d+1;
    }
    return 0;
}
