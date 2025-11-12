#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,a[111];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,t;
    cin>>n>>m;
    t=n*m;
    int u;
    for(i=1;i<=t;i++){
        cin>>a[i];
        if(i==1){
            u=a[i];
        }
    }
    bool r=false,f=false;
    sort(a+1,a+1+t,cmp);
    int x=1,y=1;
    for(i=1;i<=t;i++){
        if(a[i]==u)
        cout<<y<<" "<<x<<" ";
        if(x%n!=0||f==true){
            f=false;
            if(r==false){
                x++;
            }else{
                if(x>1){
                    x--;
                }
            }
        }else{
            y++;
            r=!r;
            f=true;
        }
    }
    return 0;
}
