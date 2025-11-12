#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
int a[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int k=0;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            k++;
        }
    }
    k++;
    int x=0,y=0;
    y=k/n;
    int j=k%n;
    if(j){
        y++;
        if(y&1){
            x=j;
        }else{
            x=n-j+1;
        }
    }else{
        if(y&1){
            x=n;
        }else{
            x=1;
        }
    }
    cout<<y<<" "<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
