#include<bits/stdc++.h>
using namespace std;
int b[5002];
int a[11451];
long long jie(int num){
    long long sum=1;
    for(int i=2;i<=num;i++){
        sum*=i;
    }
    return sum;
}
long long c(int n1,int n2){
    return jie(n1)/(jie(n2)*jie(n1-n2));
}
int fun(int k,int l,int r){
    long long num=0;
    for(int i=l;i<r-1;i++){
        if(a[i]==k){
            num+=c((r-i),2);
        }
        for(int j=i+1;j<r;j++){
            if(a[i]+a[j]>k){
                    num+=r-j;
                    continue;
            }
            for(int o=j+1;o<=r;o++){
                if(a[i]+a[j]+a[o]<=k)break;
                num++;
            }
        }
    }
    return num;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int qqq=1;
    if(b[1]==n){
        int num=0;
        for(int i=4;i<=n;i++)
            num+=c(n,i);
            num%=998244353;
        cout<<num;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=5000;i>=1;i--){
        while(b[i]>0){
            b[i]--;
            a[qqq]=i;
            qqq++;
        }
    }
    long long num=0;
    for(int i=4;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            num+=fun(a[j],j+1,n);
            num%=998244353;
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
