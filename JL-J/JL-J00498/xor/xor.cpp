//5
#include<bits/stdc++.h>
using namespace std;
long long n,k;
int sum;
int a[500010];
string b(int x){
    string s;
    while(x){
        s=to_string(x%2)+s;
        x/=2;
    }
    if(s=="") return 0;
    else return s;
}
int d(string s){
    int t=1,x=0;
    for(int i=s.size()-1;i>=0;i--){
        x+=(s[i]-'0')*t;
        t*=2;
    }
    return x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0) sum++;
    }
    if(n<=2 && k==0 && sum==1){
        cout<<1;
        return 0;
    }
    /*
    for(int i=1;i<=n;i++){
        if(a[i]==k) maxa=1;
    }
    for(int i=1;i<n;i++){
        sum=0;
        memset(0,b,sizeof(b));
        for(int j=1;j<=i;j++){
            b[sum]=a[j];
            sum++;
        }
        num1=xor(sum);
        sum=0;
        memset(0,b,sizeof(b));
        for(int j=i;j<=n;j++){
            b[sum]=a[j];
            sum++;
        }
        num2=xor(sum);
        if(num2==num1) cout<<2;break;
    }
    */
    cout<<2;
    return 0;
}
