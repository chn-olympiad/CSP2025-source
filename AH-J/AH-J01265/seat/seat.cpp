#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int a[105],id1;
int b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=100;i>=0;i--){
        id1+=b[i];
        if(i==a[1]) break;
    }
    int line=(id1-1)/n+1;
    cout<<line<<" ";
    if(line%2==0){
        cout<<n-id1%n+1;
    }else{
        cout<<(id1-1)%n+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
