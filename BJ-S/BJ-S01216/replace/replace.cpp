#include<bits/stdc++.h>
using namespace std;
#define maxn 5000005
#define mod1 998244353
#define mod2 1000000007
#define int long long
int n,q,cnth11[maxn],cnth12[maxn],cnth21[maxn],cnth22[maxn],l[maxn],hs11[maxn],hs12[maxn],hs21[maxn],hs22[maxn];
int power(int x,int y,int mod){
    if(!y){
        return 1;
    }
    if(y==1){
        return x;
    }
    int ret=power(x,y>>1,mod);
    ret=(ret*ret)%mod;
    if(y&1){
        ret=(ret*x)%mod;
    }
    return ret;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        l[i]=s1.size();
        for(int j=0;j<s1.size();j++){
            hs11[i]=(hs11[i]*114+s1[j]-'a'+1)%mod1;
            hs12[i]=(hs12[i]*514+s1[j]-'a'+1)%mod2;
            hs21[i]=(hs21[i]*114+s2[j]-'a'+1)%mod1;
            hs22[i]=(hs22[i]*514+s2[j]-'a'+1)%mod2;
        }
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        int len=t1.size();
        for(int j=0;j<len;j++){
            cnth11[j+1]=(cnth11[j]*114+t1[j]-'a'+1)%mod1;
            cnth12[j+1]=(cnth12[j]*514+t1[j]-'a'+1)%mod2;
            cnth21[j+1]=(cnth21[j]*114+t2[j]-'a'+1)%mod1;
            cnth22[j+1]=(cnth22[j]*514+t2[j]-'a'+1)%mod2;
        }
        for(int j=1;j<=len;j++){
            for(int k=1;k<=n;k++){
                if(j-1+l[k]>len){
                    continue;
                }
                int num1=cnth11[j-1]*power(114,len-j+1,mod1)%mod1;
                num1=(num1+hs11[k]*power(114,len-j-l[k]+1,mod1))%mod1;
                num1=(num1+cnth11[len]-cnth11[j+l[k]-1]*power(114,len-j-l[k]+1,mod1)%mod1+mod1)%mod1;
                int num2=cnth12[j-1]*power(514,len-j+1,mod2)%mod2;
                num2=(num2+hs12[k]*power(514,len-j-l[k]+1,mod2))%mod2;
                num2=(num2+cnth12[len]-cnth12[j+l[k]-1]*power(514,len-j-l[k]+1,mod2)%mod2+mod2)%mod2;
                int num3=cnth11[j-1]*power(114,len-j+1,mod1)%mod1;
                num3=(num3+hs21[k]*power(114,len-j-l[k]+1,mod1))%mod1;
                num3=(num3+cnth11[len]-cnth11[j+l[k]-1]*power(114,len-j-l[k]+1,mod1)%mod1+mod1)%mod1;
                int num4=cnth12[j-1]*power(514,len-j+1,mod2)%mod2;
                num4=(num4+hs22[k]*power(514,len-j-l[k]+1,mod2))%mod2;
                num4=(num4+cnth12[len]-cnth12[j+l[k]-1]*power(514,len-j-l[k]+1,mod2)%mod2+mod2)%mod2;
                if(num1==cnth11[len]&&num2==cnth12[len]&&num3==cnth21[len]&&num4==cnth22[len]){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
