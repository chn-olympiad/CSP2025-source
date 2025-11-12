#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int tx=1,ty=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            cout<<tx<<' '<<ty;
            return 0;
        }
        if(tx%2==1){
            if(ty==m){
                tx++;
            }else{
                ty++;
            }
        }else{
            if(ty==1){
                tx++;
            }else{
                ty--;
            }
        }
    }
    return 0;
}
