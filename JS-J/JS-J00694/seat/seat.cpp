#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,m;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=1,y=1;//x hang ; y lie
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a+1,a+n*m+1);
    int flagx=0;// xia wei 0 ;shang wei 1
    for(int i=n*m;i>=1;i--){
        if(a[i]==ans) cout<<y<<" "<<x;
        else{
            if(flagx==0) x++;
            if(flagx==1) x--;
            if(x>n){
                y++;
                x--;
                flagx=1;
            }
            if(x<1){
                y++;
                x++;
                flagx=0;
            }
        }
    }
    return 0;
}