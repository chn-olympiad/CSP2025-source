#include<bits/stdc++.h>
using namespace std;
int n,m,R,pos,c,a[101];
bool flag;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            pos=i;
            break;
        }
    }
    c=pos/n;
    if(pos%n) c++;
    cout<<c<<" ";
    if(pos%n==0){
        if(c%2){
            cout<<n;
        }else{
            cout<<1;
        }
    }else{
        if(c%2){
            cout<<pos-(c-1)*n;
        }else{
            cout<<c*n-pos+1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
