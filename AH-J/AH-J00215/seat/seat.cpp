#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,a[200],x,k;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(long long j=1;j<=m;j++){
        if(j%2==1){
            for(long long i=1;i<=n;i++){
                k++;
                if(a[k]==x){
                    cout<<j<<" "<<i;
                }
            }
        }else{
            for(long long i=n;i>=1;i--){
                k++;
                if(a[k]==x){
                    cout<<j<<" "<<i;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdin);
}
