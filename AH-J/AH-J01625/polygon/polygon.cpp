#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],m;
long long cnt,b[12500005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[0]++;
    b[a[1]]++;
    b[a[1]+a[2]]++;
    b[a[2]]++;
    m=a[1]+a[2];
    for(int i=3;i<=n;i++){
        for(int j=a[i]+1;j<=m;j++){
            if(b[j]){
                cnt+=b[j];
            }
        }
        for(int j=m;j>=0;j--){
            b[j+a[i]]+=b[j];
            b[j]%=998244353;
        }
        m+=a[i];
        cnt%=998244353;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
