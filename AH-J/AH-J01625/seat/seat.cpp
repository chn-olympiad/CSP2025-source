#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],b,c,d,e;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=m*n;i++){
        if(a[i]==b){
            c=m*n-i+1;
        }
    }
    d=(c-1)/m+1;
    if(d%2==1){
        e=(c-1)%m+1;
    }else{
        e=n-(c-1)%m;
    }
    cout<<d<<" "<<e;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
