#include<bits/stdc++.h>
using namespace std;
long long zuowei[100000][100000],a[10000000],c,n,r,h,m,shuchu1,shuchu2;
void pai(int x){
    if(x/n==1){
        cout<<1<<""<<x;

    }
    else
    int l=x/n;
    int y=x%n;
    if(y!=0){
        
    if((l+1)%2!=0){
    cout<<l+1<<y;
    }
    else cout<<l+1<<m-y;
    }
    else
    if(l%2!=0){
    cout<<l<<y;
    }
    else
    cout<<l<<m-y;

}


int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>c;\
if(n==m&&m==1&&n==1){
	cout<<1<<" "<<1;
}
else
for(int i=1;i<=n*m-1;i++){
    cin>>a[i];
}
for(int i=1;i<=m*n;i++){
    for(int j=i;j<=2;j++){
        if[a[j]>a[j-1]]{
            int t=a[j-1];
            a[j-1]=a[j];
            a[j]=t;
        }
    }
}
for(int i=1;i<=m*n;i++){
    if(c>a[i]&&c<a[i-1]){
        pai(i);
        break;
    }
}





    return 0;
}
