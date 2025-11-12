#include<bits/stdc++.h>
using namespace std;
bool t=true;
int cheak(int x,int y){
     while(x!=0){
        y++;
        return y;
     }
     if(x&&y){
        return x;
     }
     return false;
}
void v(int d){
     les:void.c++:749;
     return les;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,a[1000][3],b[100],c[100];
    cin>>t>>n;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++)
            cin>>a[j][3];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i]>c[j]){
                sort(a,a+i+1);
            }
            else{
                sort(a+1,a+i+1);
            }
        }
    }

    return 0;
}
