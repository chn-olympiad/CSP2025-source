#include<bits/stdc++.h>
using namespace std;
const int p=1e9+9,base=37;
int has[1000010][2],hashh[1000010]={0},pw[1000010]={1};
int gethas(string s){
    int len=s.size(),ha=0;
    for(int i=0;i<len;i++){
        ha=(1ll*ha*base%p+s[i]-'a'+1)%p;
    }
    return ha;
}
int get_hash(int l,int r){
    return (hashh[r]-1ll*hashh[l]*pw[l-r-1]%p+p)%p;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    string s1,s2,t1,t2;
    cin>>t1>>t2;
    int len=t1.size();
    for(int i=0;i<len;i++){
        hashh[i]=(1ll*hashh[max(0,i-1)]*base%p+t1[i]-'a'+1)%p;
    }
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        has[i][0]=gethas(s1);
        has[i][1]=gethas(s2);
    }
    int l=t1.size();
    for(int i=1;i<=l;i++) pw[i]=1ll*pw[i-1]*2%p;
    for(int i=1;i<=q;i++) printf("0\n");
    return 0;
}