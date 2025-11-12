#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            int p,q;
            if(i%n!=0) p=floor(i/n)+1;
            else p=i/n;
            if(p%2==0){
                if(i%n==0) q=1;
                else q=n-i%n+1;
            }
            else{
                if(i%n==0) q=n;
                else q=i%n;
            }
            cout<<p<<" "<<q;
            return 0;
        }
    }
    return 0;
}
