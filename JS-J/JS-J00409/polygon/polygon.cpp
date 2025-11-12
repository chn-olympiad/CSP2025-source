#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n;
int a[5001];
long long cnt;
int check1(int k){
    int num=0;
    for(int i=1;i<=k;i++){
        num+=a[i];
    }
    if(num<=a[k]*2){
        k--;
        check1(k);
    }
    return k;
}
void check2(int k){
    int x=a[k];
    int num=x;
    for(int i=k-1;i>=2;i--){
        num=x+a[i];
        for(int j=i-1;j>=1;j--){
            num+=a[j];
            if(num>x*2){
                cnt++;
                cnt+=j*(j-1)/2;
                num-=a[j];
                cnt%=p;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    int num=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        num+=a[i];
    }
    sort(a+1,a+n+1);
    if(num<=a[n]*2){
        n--;
        n=check1(n);
        if(n<3){
            printf("0");
            return 0;
        }
        else{
            for(int i=n;i>=3;i--){
                check2(i);
            }
        }
    }
    else{
        for(int i=n;i>=3;i--){
            check2(i);
        }
    }
    printf("%lld",cnt);
    return 0;
}
