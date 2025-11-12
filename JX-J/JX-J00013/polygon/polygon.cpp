#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[5005],ans=0;
int n,l=1;
bool s[5005];
void dt(int x){
    s[x]=1;
    long long num=0,sum=0;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        if(s[i]==1){
            num++;
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }

    }
    sum-=maxn;
    if(num>=3 && sum>maxn){
        ans++;


    }
    for(int i=l;i<=n;i++){
        if(s[i]==0){
            l=i;
            dt(i);
            s[i]=0;

        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        l=i;
        dt(i);

        for(int j=1;j<=n;j++){
            s[j]=0;
        }
    }
    cout << ans;
}
