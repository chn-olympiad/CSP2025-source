#include<bits/stdc++.h>
using namespace std;
int a1[110],a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,now,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a1[i];
    }now=a1[1];
    sort(a1+1,a1+n*m+1);
    for(int i=1;i<=n*m;i++){
        a[i]=a1[n*m-i+1];
        if(a[i]==now){
            s=i;
        }
    }
    if(s%n!=0){
        cout<<int(s/n)+1<<' ';
    }else{
        cout<<int(s/n)<<' ';
    }
    if(s%n!=0){
        if((int(s/n)+1)%2!=0){
            cout<<s%n;
        }
        else{
            cout<<n-(s%n)+1;
        }
    }else{
        if((int(s/n))%2!=0){
            cout<<n;
        }
        else{
            cout<<1;
        }
    }
    return 0;
}
