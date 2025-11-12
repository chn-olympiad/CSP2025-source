#include<bits/stdc++.h>
using namespace std;
int r,a[105],n,m,b[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    r=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    int it;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            it=i;
            break;
        }
    }
    int l;
    //cout<<it<<" ";
    if(it%n!=0){
        l=it/n+1;
    }else{
        l=it/n;
    }
    it%=n;
    if(it==0) it=n;
    cout<<l<<" ";
    if(l%2==0){
        cout<<n-it+1;
    }else {
        cout<<it;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

