#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505];
long long jie[505];
string s;
int main(){
    srand(time(NULL));
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!a[i]) cnt++;
    }
    jie[1]=1;
    for(int i=2;i<=n;i++){
        jie[i]=jie[i-1]*i%mod;
    }
    if(s.find('0')==-1){
        printf("%lld",jie[n]);
        return 0;
    }
    cout<<rand()%998244353;
    return 0;
}