#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int cnt){
    for(int i=1;i<=cnt;i++){
        for(int j=i;j<=cnt;j++)
            if(a[i]<a[j])
                swap(a[i],a[j]);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1005],r,seat[15][15],num=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    r=a[1];
    sort(a,n*m);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[++num]==r){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[++num]==r){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
