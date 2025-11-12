#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1],id=0;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            id=i;
            break;
        }
    }
    int c=id/n;
    if(id%n!=0)c++;
    int r=0;
    if(c%2==1){
        r=(id%n);
        if(r==0)r=n;
    }
    else{
        int tmp=(id%n);
        if(tmp==0)tmp=n;
        r=(n-tmp+1);
    }
    cout<<c<<" "<<r;
    return 0;
}
