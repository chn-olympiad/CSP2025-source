#include <bits/stdc++.h>
using namespace std;
int n,m,a[100100];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int tmp=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==tmp){
            int t1=(i+n-1)/n;
            if(t1%2==0){
                if(i%n!=0) cout<<t1<<" "<<n-i%n+1;
                else cout<<t1<<" "<<1;
            }else{
                if(i%n!=0) cout<<t1<<" "<<i%n;
                else cout<<t1<<" "<<n;
            }
        }
    }

    return 0;
}
