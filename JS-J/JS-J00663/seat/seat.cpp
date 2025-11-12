#include<bits/stdc++.h>
using namespace std;
int n,m,s,i,f,p=0;
int a[10001],k[10001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+n*m);
    f=n*m;
    for(int i=1;i<=n*m;i++){
        k[i]=a[f];
        f--;
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int f=1;f<=n;f++){
                p++;
                if(s==k[p]){
                    cout<<i<<" "<<f;
                }
            }
        }
        if(i%2==0){
            for(int f=n;f>=1;f--){
                p++;
                if(s==k[p]){
                    cout<<i<<" "<<f;
                }
            }
        }
    }
    return 0;
}
