#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],x,id;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            id=i;
            break;
        }
    }//cout<<id<<endl;
    cout<<id/m+min(1,id%m)<<" ";
    if(!((id/m+min(1,id%m))%2)){
        cout<<n-(id-1)%m;
    }else{
        cout<<(id-1)%m+1;
    }
    fclose(stdin);
    fclose(stdout);
}
