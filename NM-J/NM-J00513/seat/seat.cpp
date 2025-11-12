#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin>>n>>m;
int x=a[0],y;
int z;
for(int i=0;i<n*m;i++)cin>>a[i];
sort(a,a+n*m,greater<int>());
for(int i=0;i<n*m;i++){
    if(a[i]==x){
        z=i;
        if(i%n==0){
            cout<<i/n;
            y=i/n;
            break;
    }
    else if(i%n!=0){
        cout<<i/n+1;
        y=i/n+1;
        break;
    }
}
}
    if(y==1)cout<<z;
    if(y%2==0&&y!=1){
        cout<<z-((y-1)*n+1)+1;
    }
    else cout<<(y-1)*n+1-z+1;
return 0;
}
