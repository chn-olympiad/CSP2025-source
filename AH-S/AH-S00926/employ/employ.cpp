#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
string s;
int b[505],a[505];
long long MOD=998244353,sum,ans,x=1;
long long start(int step,int cnt,int l){
    long long tmp=0;
    if(l==m){
        tmp=1;
        for(int i=sum;i>=2;i--){
            tmp=tmp*i%MOD;
        }
        return tmp*(x%MOD)%MOD;
    }
    if(step>n||l+n-a[cnt]<m){
        return 0;
    }
    if(s[step]=='0'){
        for(int i=0;i<=n;i++){
            if(b[i]){x=x*b[i];
                b[i]--;sum--;
                tmp+=start(step+1,cnt+1,l);
                b[i]++;sum++;x/=b[i];
            }
        }
    }else{
        for(int i=0;i<=n;i++){
            if(b[i]){x=x*b[i];
                b[i]--;sum--;
                tmp+=start(step+1,cnt+(i<=cnt),l+(i>cnt));
                b[i]++;sum++;x/=b[i];
            }
        }
    }return tmp;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;s=" "+s;sum=n;
    for(int i=1,x;i<=n;i++){
        cin>>x;b[x]++;
    }for(int i=1;i<=n;i++){
        a[i]+=b[i]+a[i-1];
    }
    cout<<start(1,0,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
