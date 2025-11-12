#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1111];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    for(int i=2;i<=n*m;i++)cin>>a[i];
    a[1]=k;
    sort(a+1,a+n*m+1,cmp);
    int p;
    for(int i=1;i<=n*m;i++) if(a[i]==k) p=i;
    int x=1,y=0;
    for(int i=1;i<=n*m;i++){
        y++;
        if(i==p){
            cout<<x<<" "<<y;
            break;
        }
        if(y==m){
            y=m;
            for(int j=1;j<=n*m;j++){
                y--;
                if(j==p){
                    cout<<x<<" "<<y;
                    return 0;
                }
                if(y==1){
                    y=1;
                    x++;
                    break;
                }
            }
        }
    }
    return 0;
}
