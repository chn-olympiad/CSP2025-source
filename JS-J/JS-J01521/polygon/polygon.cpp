#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int MAXN=5005;
int n;
int a[MAXN];
long long sum[MAXN];
void init(){
    sum[0]=1;
    for(int i=1;i<=5000;i++)sum[i]=(sum[i-1]*2)%mod;
}
long long ans=0;
void deal(int x){
    //cout<<x<<endl;
    int x1;
    int p=x;
    long long num=0;
    long long num1=0;
    int pl;
    while(p<=n-2){
        p+=1;
        x1=a[p];
        pl=p+1;
        while(x1+a[x]>a[pl]&&pl<=n){
            pl+=1;
            num+=1;
        }
        while(x1+a[x]>a[pl]-a[1]&&pl<=n){
            pl+=1;
            num1+=1;
        }
        //cout<<p<<" "<<x<<" "<<pl<<endl;
        num%=mod;
    }
    ans=(ans+num*sum[x-1]%mod+num1*(sum[x-1]-1))%mod;
    //cout<<ans<<" "<<num<<" "<<sum[x-1]<<endl;
}
int main(){
    init();
    scanf("%d",&n);
    int suma=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(suma<=10000)suma+=a[i];
    }
    sort(a+1,a+1+n);
    while(a[n]*2>=suma)n-=1;
    //cout<<n<<endl;
    for(int i=1;i<=n-2;i++)deal(i);
    cout<<ans<<endl;
    return 0;
}
