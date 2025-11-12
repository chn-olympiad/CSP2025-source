#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int a[105];
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
    num=a[1];
    sort(a+1,a+n*m+1,cmp);
    int id=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==num)id=i;
    }
    num=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(num==id){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                num++;
            }
        }else{
            for(int j=n;j>=1;j--){
                if(num==id){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                num++;
            }
        }
    }
    return 0;
}
