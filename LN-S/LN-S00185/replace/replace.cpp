#include<bits/stdc++.h>
#define piiii pair<pair<int,int>,pair<int,int>>
using namespace std;
const int N=5e6+5,mod1=1e9+7,mod2=998244353,p=131;
char s1[N],s2[N];
int n,Q,cnt;
int h11[N],h12[N],h21[N],h22[N],q1[N],q2[N];
map<piiii,int>mp;
struct Node{
    int len,h11,h12,h21,h22;
};
vector<Node>v[N];
void hash1(){
    int len1=strlen(s1+1),len2=strlen(s2+1);
    q1[0]=1,q2[0]=1;
    for(int i=1;i<=len1;i++)  q1[i]=q1[i-1]*p%mod1,q2[i]=q2[i-1]*p%mod2;
    if(len1!=len2)  return;
    for(int i=1;i<=len1;i++){
        h11[i]=(h11[i-1]*p%mod1+(s1[i]-'a'+1))%mod1;
        h12[i]=(h12[i-1]*p%mod2+(s1[i]-'a'+1))%mod2;
    }
    for(int i=1;i<=len2;i++){
        h21[i]=(h21[i-1]*p%mod1+(s2[i]-'a'+1))%mod1;
        h22[i]=(h22[i-1]*p%mod2+(s2[i]-'a'+1))%mod2;
    }
    int g=1;
    for(int i=len1;i>=1;i--){
        if(s1[i]!=s2[i])  g=i;
    }
    for(int i=g;i<=len1;i++){
        if(!mp[{{h11[i],h12[i]},{h21[i],h22[i]}}])    mp[{{h11[i],h12[i]},{h21[i],h22[i]}}]=++cnt;
        v[mp[{{h11[i],h12[i]},{h21[i],h22[i]}}]].push_back({len1-i,(h11[len1]-h11[i]*q1[len1-i]%mod1+mod1)%mod1,(h12[len1]-h12[i]*q2[len1-i]%mod2+mod2)%mod2,(h21[len1]-h21[i]*q1[len1-i]%mod1+mod1)%mod1,(h22[len1]-h22[i]*q2[len1-i]%mod2+mod2)%mod2});
    }
}
int hash2(){
    int len1=strlen(s1+1),len2=strlen(s2+1);
    q1[0]=1,q2[0]=1;
    for(int i=1;i<=len1;i++)  q1[i]=q1[i-1]*p%mod1,q2[i]=q2[i-1]*p%mod2;
    if(len1!=len2)  return 0;
    for(int i=1;i<=len1;i++){
        h11[i]=h11[i-1]*(s1[i]-'a'+1)%mod1;
        h12[i]=h12[i-1]*(s1[i]-'a'+1)%mod2;
    }
    for(int i=1;i<=len2;i++){
        h21[i]=h21[i-1]*(s2[i]-'a'+1)%mod1;
        h22[i]=h22[i-1]*(s2[i]-'a'+1)%mod2;
    }
    int g1=n;
    for(int i=1;i<=len1;i++){
        if(s1[i]!=s2[i])  g1=i;
    }
    int g2=1;
    for(int i=len1;i>=1;i--){
        if(s1[i]!=s2[i])  g2=i;
    }
    // if(g1<=g2){
    //     for(int i=1;i<=g1;i++){
    //         if(mp[{{(h11[g2]-h11[i]*q1[(g2-i)]%mod1+mod1)%mod1,{(h12[i]-h12[i]*q2[(g2-i)]%mod2+mod2)%mod2},{(h21[i]-h21[i]*q1[(g2-i)]%mod1+mod1)%mod1,(h22[i]-h22[i]*q2[(g2-i)]%mod2+mod2)%mod2}])
    //     }
    // }
    
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++){
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        hash1();
    }
    for(int i=1;i<=Q;i++){
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        hash2();
        printf("0\n");
    }
}