#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b[1000];
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int sc=b[1];
    int a[1000];
    sort(b+1,b+n*m+1);
    int siz=n*m,sizz=1;
    for(int i=siz;i>=1;i--){
        a[sizz++]=b[i];
    }
    int q;
    for(int i=1;i<=siz;i++){
        if(a[i]==sc){
            q=i;
            break;
        }
    }
    if((q/n)%2==0){
        cout<<q/n+min(1,q%n)<<' '<<1+(max(1,q%n)-1);
    }else{
        cout<<q/n+min(1,q%n)<<' '<<n-(max(1,q%n)-1);
    }
    return 0;
}