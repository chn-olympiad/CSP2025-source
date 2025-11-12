#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101]={};
long long h,l;//Hang(2)Lie(4)
long long r,ar;
int main(){
    freopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ar=a[1];
    sort(a+1,a+n*m+1);
    //for(long long i=1;i<=n*m;i++){
    //    cout<<a[i]<<" ";
    //}
    for(long long i=1;i*2<=n*m;i++){
        long long ls=a[i];
        a[i]=a[n*m-i+1];
        a[n*m-i+1]=ls;
    }
    //printf("\n");
    //for(long long i=1;i<=n*m;i++){
    //    cout<<a[i]<<" ";
    //}
    //--------------------------------
    for(long long i=1;i<=n*m;i++){
        if(a[i]==ar){
            r=i;
            break;
        }
    }
    if(((r-1)/n+1)%2){
        l=(r-1)/n+1;
        h=r%n;
        if(h==0)h=n;
    }else{
        l=(r-1)/n+1;
        h=((r-1)/n+1)*n-r+1;
    }
    printf("%lld %lld",h,l);
    fclose(stdout);
    fclose(stdin);
    return 0;
}
