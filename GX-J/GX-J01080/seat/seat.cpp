#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){return x>y;}
int n,m,a[1000],x=1,y=0,k;
bool f=true;
int main(){
    //freopen("seat1.in","r",stdin);
    //freopen("seat1.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){cin>>a[i];}
    k=a[0];sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n*m;i++){
        if(x==m)y++;f=false;
        if(x==1)y++;f=true;
        if(f)x++;
        else x--;
        if(a[i]==k){cout<<x<<" "<<y;return 0;}
    }
}
