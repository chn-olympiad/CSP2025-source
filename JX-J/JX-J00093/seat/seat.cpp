#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[110];
int s, a1;
int l, h;

bool cmp(int b, int c){
    return b>c;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1; i<=n*m; i++){
        if(a[i]==a1){
            s=i;
        }
    }
    cout<<(s-1)/n+1<<" ";
    l=(s-1)/n+1;
    if(l%2==1){
        cout<<(s-1)%n+1;
    }else{
        cout<<n-(s-1)%n;
    }
    return 0;
}

