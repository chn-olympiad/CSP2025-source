#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],self;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    self=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==self){
            self=i;
            break;
        }
    }
    for(int k=1,i=1,j=1;k<=n*m;k++){
        if(k==self){
            cout<<j<<" "<<i;
            break;
        }
        if(j%2==1)i++;
        else i--;
        if(i>n)i=n,j++;
        if(i<1)i=1,j++;
    }
    return 0;
}
