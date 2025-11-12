#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long sum=0;
    int a[5002];
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=pow(2,n);i++){
        long long num;
        int maxn=0;
        int p=i;
        int lo=1;
        while(p){
            if(p%2==1){
                num=num+a[lo];
                maxn=max(maxn,a[lo]);
            }
            p=p/2;
            lo++;
        }
        if(num>maxn*2)sum++;
        sum=sum%998224353;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
