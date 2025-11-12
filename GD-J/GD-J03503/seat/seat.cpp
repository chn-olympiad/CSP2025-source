#include <bits/stdc++.h>
using namespace std;
int a[1001];
string x;
bool cmp(int x,int y){
    return y<x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,xr;
    cin>>n>>m>>xr;
    a[0]=xr;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }sort(a,a+n*m,cmp);
    int st=0,j=0;
    for(int i=1;i<=m;i++){
        if(st==0){
            for(int x=1;x<=n;x++){
                if(a[j]==xr){
                    cout<<i<<' '<<x;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                j++;
            }st=1;
        }else{
            for(int x=n;x>0;x--){
                if(a[j]==xr){
                    cout<<i<<' '<<x;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                j++;
            }st=0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
