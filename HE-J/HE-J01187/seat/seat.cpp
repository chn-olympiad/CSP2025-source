#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10086];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xl=a[1];
    sort(a+1,a+n*m+1);
    int b[10086];
    for(int i=1;i<=n*m;i++){
        b[i]=a[n*m-i];
    }
    for(int i=1;i<=n*m;i++){
        if(b[i]==xl){
            int c=i/m,r;
            if(c%2==1) r=i%n+1;
            else r=n-(i%n)-1;
            cout<<c<<" "<<r<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}