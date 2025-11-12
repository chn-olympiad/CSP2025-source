#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,hang,lie;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m+10];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            x++;
        }
    }
    lie=x/n;
    if(x%n!=0){
        lie++;
    }
    if(lie%2!=0){
        hang=x%n;
        if(hang==0){
            hang=n;
        }
    }
    else{
        if(x%n!=0){
            hang=n-(x%n-1);
        }
        else{
            hang=1;
        }
    }
    cout<<lie<<' '<<hang;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
