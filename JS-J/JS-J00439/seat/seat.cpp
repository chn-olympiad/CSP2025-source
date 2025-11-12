#include<bits/stdc++.h>
using namespace std;
int n,m,num,a[1000],point;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    num=n*m;
    for(int i=1;i<=num;i++){
        cin>>a[i];
    }
    point=a[1];
    sort(a+1,a+1+num,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[(i-1)*m+j]==point){
                if(i%2==1){
                    cout<<i<<" "<<j;
                }
                else{
                    cout<<i<<" "<<m-j+1;
                }
            }
        }
    }
    return 0;
}
