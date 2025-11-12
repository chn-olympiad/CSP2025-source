#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p,cnt,a[105],b[15][15];
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
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i&1){
            for(int j=1;j<=n;j++){
                cnt++;
                if(a[cnt]==p){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                cnt++;
                if(a[cnt]==p){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
