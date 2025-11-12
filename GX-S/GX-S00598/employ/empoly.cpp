#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[1010],f;char s[1010];long long ans,sum;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("employ2.in","r",stdin),freopen("employ2.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){cin>>c[i];}
    sort(c+1,c+1+n),sort(s,s+n,cmp);
    do{
        do{
            for(int i=1;i<=n;i++){
                if(m==c[i]){m++;continue;}
                if(s[i]=='0')m++;
                else {sum++;sum=sum%mod;}
            }
            if(sum>m)ans++;
        }while(next_permutation(s,s+n));
        ans%=mod;
    }while(next_permutation(c+1,c+1+n));
    cout<<ans;
}
