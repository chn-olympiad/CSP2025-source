#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,zuo[20][20],ziji;
int a[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ziji=a[1];
    sort(a+1,a+n*m+1,cmp);
    int bu=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                bu++;
                if(a[bu]==ziji){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                bu++;
                if(a[bu]==ziji){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
	return 0;
}
