#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],xn,ans,cw[100][100];
inline bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    xn=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==0){
            //hou
            for(int j=m;j>=1;j--){
                ans++;
                cw[j][i]=a[ans];
                if(cw[j][i]==xn){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            //zhen
            for(int j=1;j<=m;j++){
                ans++;
                cw[j][i]=a[ans];
                if(cw[j][i]==xn){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
