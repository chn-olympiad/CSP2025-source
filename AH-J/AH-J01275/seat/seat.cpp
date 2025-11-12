#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l;
    cin>>n>>m;
    int a[120]={0},b[120]={0},c[120]={0};
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    l=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    c[0]=1;
    int k=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            b[a[k]]=i;
            if(j==1){
                c[a[k]]=c[a[k-1]];
                k++;
                continue;
            }
            if(i%2==0){
                c[a[k]]=c[a[k-1]]-1;
            }else{
                c[a[k]]=c[a[k-1]]+1;
            }
            k++;
        }
    }
    cout<<b[l]<<" "<<c[l];
    return 0;
}
