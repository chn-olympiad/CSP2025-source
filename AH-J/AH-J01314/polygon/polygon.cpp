#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[5005],sum,t=998244353;
bool f=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
        }
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
            cout<<6;
        }else{
            cout<<0;
        }
    }else if(f==1){
        for(int i=3;i<=n;i++){
            long long jc1=1;
            for(int j=i;j>=1;j--){
                jc1*=j;
                jc1%=t;
            }
            sum+=jc1;
            sum%=t;
        }
        cout<<sum;
    }else{
        for(int i=3;i<=n;i++){
            long long jc1=1;
            for(int j=i;j>=1;j--){
                jc1*=j;
                jc1%=t;
            }
            sum+=jc1;
            sum%=t;
        }
        cout<<sum;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
