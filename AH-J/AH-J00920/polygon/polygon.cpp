#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[5005],sum[5005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n<=3){
        if(n==3&&2*a[3]>a[1]+a[2]+a[3]){
            cout<<1;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
