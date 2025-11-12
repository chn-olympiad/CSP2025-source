#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long c(int n,int m){
    int maxn=max(m,n-m),minn=min(m,n-m);
    long long sum=1,ls1=1,ls2=1;
    for(int i=maxn;i<=n;i++){
        ls1*=i;
        ls1%=MOD;
    }
    for(int i=1;i<=minn;i++){
        ls2*=i;
        ls2%=MOD;
    }
    sum=(((sum*ls1)%MOD)/ls2)%MOD;
    return sum;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int cntn=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==0)cntn++;
    }
    n-=cntn;
    if(n<m){
        cout<<0;
        return 0;
    }
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=c(n,i);
        sum%=MOD;
    }
    cout<<sum;
    return 0;
}
