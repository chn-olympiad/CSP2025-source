#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int mod=1e9+7;
int n,q;
unsigned long long s11[200010],s21[200010],p1[5000010];
unsigned long long s12[200010],s22[200010],p2[5000010];
unsigned long long a1[5000010],a2[5000010];
unsigned long long b1,b2;
int len[200010];
char s1[5000010],s2[5000010];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    p1[0]=p2[0]=1;
    for(int i=1;i<=5000010;i++){
        p1[i]=p1[i-1]*131;
        p2[i]=p2[i-1]*13331%mod;
    }
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",s1+1);
        len[i]=strlen(s1+1);
        for(int j=1;j<=len[i];j++){
            s11[i]=s11[i]*131+s1[j];
            s12[i]=(s12[i]*13331+s1[j])%mod;
        }
        scanf("%s",s1+1);
        for(int j=1;j<=len[i];j++){
            s21[i]=s21[i]*131+s1[j];
            s22[i]=(s22[i]*13331+s1[j])%mod;
        }
    }
    while(q--){
        scanf("%s%s",s1+1,s2+1);
        int m=strlen(s1+1);
        if(m!=strlen(s2+1)){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=m;i++){
            a1[i]=a1[i-1]*131+s1[i];
            a2[i]=(a2[i-1]*13331+s1[i])%mod;
        }
        for(int i=1;i<=m;i++){
            b1=b1*131+s2[i];
            b2=(b2*13331+s2[i])%mod;
        }
        int s,t;
        for(int i=1;i<=m;i++){
            if(s1[i]!=s2[i]){
                s=i;
                break;
            }
        }
        for(int i=m;i>=1;i--){
            if(s1[i]!=s2[i]){
                t=i;
                break;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(len[i]<t-s){
                continue;
            }
            for(int j=max(t-len[i]+1,1);j<=s&&j+len[i]-1<=m;j++){
               // cout<<j<<"~"<<j+len[i]-1<<":\n"<<"   s11 "<<s11[i]<<"\n    s12 "<<s12[i]<<"\n    a1 "<<a1[j+len[i]-1]-a1[j-1]*p1[len[i]]<<"\n    a2 "<<(a2[j+len[i]-1]+mod-a2[j-1]*p2[len[i]]%mod)%mod<<endl;
                if(s11[i]==a1[j+len[i]-1]-a1[j-1]*p1[len[i]]&&s12[i]==(a2[j+len[i]-1]+mod-a2[j-1]*p2[len[i]]%mod)%mod){
                   // cout<<a1[m]+(s21[i]-s11[i])*p1[m-j-len[i]+1]<<" "<<b1<<endl;
                   // cout<<(a2[m]+mod+(s22[i]-s12[i]+mod)*p2[m-j-len[i]+1]%mod)%mod<<" "<<b2<<endl;
                    if(a1[m]+(s21[i]-s11[i])*p1[m-j-len[i]+1]==b1&&(a2[m]+mod+(s22[i]-s12[i]+mod)*p2[m-j-len[i]+1]%mod)%mod==b2){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
