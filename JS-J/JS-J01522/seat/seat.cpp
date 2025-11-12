#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i,j,t,l=1,h=0,u=1;
    cin>>n>>m;
    for(i=0;i<=n*m-1;i++){
        cin>>a[i];
    }
    t=a[0];
    sort(a,a+n*m,cmp);
    for(i=0;i<=n*m-1;i++){
        if(l!=1&&h==1||h==n){
            l=l+1;
            u=u*(-1);
            if(a[i]==t){
                break;
            }
            i=i+1;
            h=h+u;
        }else{
            h=h+u;
        }
        if(a[i]==t){
            break;
        }
    }
    cout<<l<<" "<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
