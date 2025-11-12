#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int N=2e5+5,M=2500005,base=131;
unordered_map<ull,unordered_map<ull,int>>mp;
int n,q,cnt,idx,B,mi,mx,len[N],ans;
ull p[M],h1[M],h2[M],f1[N],f2[N];
char s1[M],s2[M];
void hashe(){
    for(int i=1;i<=cnt;i++){
        h1[i]=(h1[i-1]*base+s1[i]-'a'+1);
        h2[i]=(h2[i-1]*base+s2[i]-'a'+1);
    }
}
ull getha1(int l,int r){
    return h1[r]-h1[l-1]*p[r-l+1];
}
ull getha2(int l,int r){
    return h2[r]-h2[l-1]*p[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    B=500;
    if(q==1)
        B=4000;
    p[0]=1;
    for(int i=1;i<=M-5;i++)
        p[i]=p[i-1]*base;
    for(int i=1;i<=n;i++){
        scanf("%s%s",s1+1,s2+1);
        cnt=strlen(s1+1);
        hashe();
        if(h1[cnt]==h2[cnt])
            continue;
        mp[h1[cnt]][h2[cnt]]++;
        if(cnt>B){
            idx++;
            f1[idx]=h1[cnt],f2[idx]=h2[cnt],len[idx]=cnt;
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%s%s",s1+1,s2+1);
        cnt=strlen(s1+1);
        if(strlen(s2+1)!=cnt){
            printf("0\n");
            continue;
        }
        hashe();
        for(int j=1;j<=cnt;j++)
            if(s1[j]!=s2[j]){
                mi=j;
                break;
            }
        for(int j=cnt;j>=1;j--)
            if(s1[j]!=s2[j]){
                mx=j;
                break;
            }
        ans=0;
        for(int j=max(1,mx-B);j<=mi;j++)
            for(int k=mx;k<=min(cnt,j+B-1);k++){
                ull t1=getha1(j,k),t2=getha2(j,k);
                if(mp.count(t1))
                    if(mp[t1].count(t2))
                        ans+=mp[t1][t2];
            }
        if(cnt>B){
            for(int p=1;p<=idx;p++){
                for(int j=max(1,mx-len[p]+1);j<=mi&&j+len[p]-1<=cnt;j++)
                    if(getha1(j,j+len[p]-1)==f1[p]&&getha2(j,j+len[p]-1)==f2[p]){
                        ans++;
                        break;
                    }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}