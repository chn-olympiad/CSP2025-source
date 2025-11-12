#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k;
long long a[5005],cnt,maxn=-1,sum,cntt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i;j++){
                if(sum>maxn*2){
                    maxn=max(maxn,a[j]);
                    sum+=a[j];
                    cnt++;
                    j++;
                }
                if(cnt==i){
                    cntt=(cntt+1)%998244353;
                    cnt=0;
                    sum=0;
                    maxn=-1;
                    break;
                }
        }
    }
    cout<<cntt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
