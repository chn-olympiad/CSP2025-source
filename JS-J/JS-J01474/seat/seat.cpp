#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    int s,h=1;
    cin>>s;
    int x;
    for(int i=1;i<(n*m);i++){
        cin>>x;
        if(x>s) h++;
    }
    int k;
    if(h%n==0) k=h/n;
    else k=h/n+1;
    cout<<k<<" ";
    if(k%2!=0){
        if(h%n==0) cout<<n;
        else cout<<h%n;
    }
    else{
        if(h%n==0) cout<<1;
        else cout<<n-(h%n)+1;
    };

    fclose(stdin);
    fclose(stdout);
    return 0;
}
