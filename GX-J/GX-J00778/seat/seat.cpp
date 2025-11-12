#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int x=a[1],i,j;
    sort(a+1,a+n*m+1,cmp);
    for(int k=1;k<=n*m;k++){
        if(a[k]==x){
            i=ceil(k*1.0/n*1.0);
            if(i%2==1){
                if(k%n==0) j=n;
                else j=k%n;
            }else if(i%2==0){
                if(k%n==0) j=1;
                else j=n-k%n+1;
            }
            cout<<i<<' '<<j;
            break;
        }
    }
    return 0;
}
