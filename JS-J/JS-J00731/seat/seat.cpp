#include<bits/stdc++.h>
using namespace std;
struct st{
    int sc;
    int nu;
}a[101];
int n,m;
bool cmp(st x,st y){
    return x.sc>y.sc;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].sc;
        a[i].nu=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int j=0;j<m;j++){
        for(int i=1;i<=n;i++){
            if(a[j*n+i].nu==1){
                if(j%2==0){
                    cout<<j+1<<i<<"\n";
                }else{
                    cout<<j+1<<n-i<<"\n";
                }
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
