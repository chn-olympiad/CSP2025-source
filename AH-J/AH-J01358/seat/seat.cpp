#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100+10];
bool cmp(const long long &x,const long long &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=m*n;i++)scanf("%lld",&a[i]);
    k=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    long long stop=n*m,i=1,j=1,cnt=0;
    while(stop--){
        cnt++;
        if(a[cnt]==k)break;
        if((j%2==1&&i==n)||(j%2==0&&i==1))j++;
        else if(j%2==1&&i!=n)i++;
        else i--;
    }
    printf("%lld %lld",j,i);
    return 0;
}
