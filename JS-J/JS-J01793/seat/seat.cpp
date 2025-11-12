#include<bits/stdc++.h>
using namespace std;
int a[1005];int n,m;int y;int lie,hang;int x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n*m;i++){

        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n;i++){
        if(a[i]==x){
            y=n*m-i+1;
            break;
        }
    }
    if(y%n!=0){
        lie=y/n+1;
    }
    else{
        lie=y/n;
    }
    hang=y-(lie-1)*n;
    if(lie%2==0){
        hang=n-hang+1;
    }
    cout<<lie<<' '<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
