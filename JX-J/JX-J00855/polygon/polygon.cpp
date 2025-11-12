#include<iostream>
#include<algorithm>
using namespace std;
const long long N=998244353;
int a[5005];
long long s[5005],sum=1,q[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    long long num=0;
    s[n]=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]==a[i+1]){
            s[i]=s[i+1];
        }
        else{
            s[i]=1;
            for(int j=i+1;j<=n;j++){
                s[i]=(s[i]+s[j])%N;
            }
        }
        sum=(sum+s[i])%N;
    }
    long long ttt=n*(n-1)/2%N;
    sum=(sum-n-ttt+N)%N;
    cout<<sum;
    return 0;
}
