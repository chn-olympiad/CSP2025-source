#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,i,j=1,cnt[101],seat[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>seat[i];
        cnt[seat[i]]=1;
    }
    int a1=seat[1];
    for(i=100;i>=0;i--){
        if(cnt[i]){
            if(a1==i){
                a1=j;
                break;
            }
            seat[j]=i;
            j++;
        }
    }
    y=(j-1)/n+1;
    if(((j-1)/n)%2==1) x=n*y-j+1;
    else x=j%n;
    if(x==0) x=n;
    cout<<y<<" "<<x;
    return 0;
}
