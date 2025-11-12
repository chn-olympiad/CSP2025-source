#include<bits/stdc++.h>
using namespace std;
int a[1008],b[1008];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,c,d;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    c=a[1];
    sort(a+1,a+n*m+1,greater<int>{});
    for(int i=1;i<=n*m;i++){
           if(a[i]==c) d=i;
    }
    int k=d/n;
    int p=d%n;
    if(k%2==1){
        if(p!=0) cout<<k+1<<" "<<n-p+1;
        else cout<<k<<" "<<d;
    }
    else{
        if(p!=0) cout<<k+1<<" "<<p;
        else cout<<k<<" "<<p;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
