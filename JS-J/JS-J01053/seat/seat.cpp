#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n,m,r,c;
    int a[100];
    freopen("home\\user\\number\\seat.in","r",stdin);
    freopen("File\\home\\user\\Desktop\\JS-J01053\\seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    j=a[1];
    sort(a+1,a+i+1);
    for(i=1;i<=n*m;i++){
        if(a[i]==j){
            j=n*m-i+1;
            break;
        }
    }
    cout<<j<<endl;
    if(j%n==0){
        if(j/n%2==0){
            c=j/n;
            r=1;
        }
        else {
            c=j/n;
            r=n;
        }
    }
    else {
        if((j/n+1)%2==0){
            c=j/n+1;
            r=n-j%n+1;
        }
        else {
            c=j/n+1;
            r=j%n;
        }
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
