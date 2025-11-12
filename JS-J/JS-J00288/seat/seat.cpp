#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(a[i]==t){
            k=n*m-i;
            break;
        }
    }
    if((k/n)%2==0){
        cout<<k/n+1<<" "<<k%n+1;
    }else{
        cout<<k/n+1<<" "<<n-(k%n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
