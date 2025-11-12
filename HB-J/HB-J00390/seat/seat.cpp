#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],f[101],x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    f[1]=1;
    for(int i=1;i<=n*m-1;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
                swap(f[i],f[j]);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n*m;i++){
        if(f[i]==1){
            cnt=i;
            break;
        }
    }
    int cn=cnt/n;
    if(cnt%n!=0){
            cout<<cn+1<<" ";
        if((cn+1)%2==0)
            cout<<(n+1)-(cnt%n);
        else
            cout<<cnt%n;
        }else{
            if(cn%2==0){
                cout<<cn<<" ";
                cout<<1;
            }else{
                cout<<cn<<" ";
                cout<<n;
            }
        }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
