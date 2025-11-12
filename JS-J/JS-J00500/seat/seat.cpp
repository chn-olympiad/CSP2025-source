#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,s,k;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat,in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1)
            for(int i=1;i<=n;i++){
                k++;
                if(a[k]==s){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        else
            for(int i=n;i>0;i--){
                k++;
                if(a[k]==s){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
    }
}
