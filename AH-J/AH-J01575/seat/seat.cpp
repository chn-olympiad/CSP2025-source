#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    if(x>y){
        return true;
    }return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[201]={};
    int m,n;
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    int ms=a[1],mz;
    sort(a+1,a+sum+2,cmp);
    for(int i=1;i<=sum;i++){
        if(a[i]==ms){
            mz=i;
        }
    }
    int ansm,ansn;
    ansm=mz/n;
    if(ansm*n!=mz){
        ansm+=1;
    }
    if(ansm%2){
        ansn=mz-(ansm-1)*n;
    }else{
        ansn=n-(mz-(ansm-1)*n)+1;
    }
    cout<<ansm<<' '<<ansn;
    return 0;
}//#Shang4Shan3Ruo6Shui4
