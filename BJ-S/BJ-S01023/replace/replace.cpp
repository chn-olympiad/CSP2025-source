#include<bits/stdc++.h>
using namespace std;
struct st{
    long long son[26],sum;
}t[5000005];
const long long mod[2]={998244853,1000000009};
long long n,q,total,num[200005],tree_total,base[2][5000005],h[2][5000005];
char s[2][5000005];
map<pair<long long,long long>,long long>id;
unordered_map<long long,long long>mp[200005];
void insert(long long x,long long l,long long r){
    long long i=num[x],hs[2]={0,0};
    mp[x][hs[0]*mod[1]+hs[1]]=i;
    for(int b=l;b<=r;b++){
        for(int d=0;d<2;d++)hs[d]=(hs[d]*base[d][1]+s[0][b])%mod[d];
        if(!t[i].son[s[0][b]-'a'])t[i].son[s[0][b]-'a']=++tree_total;
        i=t[i].son[s[0][b]-'a'];
        mp[x][hs[0]*mod[1]+hs[1]]=i;
    }
    t[i].sum++;
}
void dfs(long long x){
    for(int b=0;b<26;b++){
        if(t[x].son[b]){
            t[t[x].son[b]].sum=t[t[x].son[b]].sum+t[x].sum;
            dfs(t[x].son[b]);
        }
    }
}
long long ask(long long x,long long l,long long r){
    while(l!=r){
        long long mid=(l+r)/2;
        if(mp[x][h[0][mid]*mod[1]+h[1][mid]])l=mid+1;
        else r=mid;
    }
    return t[mp[x][h[0][l-1]*mod[1]+h[1][l-1]]].sum;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    base[0][0]=base[1][0]=1;
    for(int b=1;b<=5000000;b++){
        base[0][b]=base[0][b-1]*131ll%mod[0];
        base[1][b]=base[1][b-1]*137ll%mod[1];
    }
    for(int b=1;b<=n;b++){
        scanf("%s%s",s[0]+1,s[1]+1);
        long long len=strlen(s[0]+1),last=len,hs[2][2]={0,0,0,0};
        for(int c=1;c<=len;c++)if(s[0][c]!=s[1][c])last=c;
        for(int c=1;c<=last;c++)for(int d=0;d<2;d++)for(int e=0;e<2;e++)hs[d][e]=(hs[d][e]*base[e][1]+s[d][c])%mod[e];
        if(!id[{hs[0][0]*mod[1]+hs[0][1],hs[1][0]*mod[1]+hs[1][1]}]){
            id[{hs[0][0]*mod[1]+hs[0][1],hs[1][0]*mod[1]+hs[1][1]}]=++total;
            num[total]=++tree_total;
        }
        insert(id[{hs[0][0]*mod[1]+hs[0][1],hs[1][0]*mod[1]+hs[1][1]}],last+1,len);
    }
    for(int b=1;b<=total;b++)dfs(num[b]);
    for(int b=1;b<=q;b++){
        scanf("%s%s",s[0]+1,s[1]+1);
        long long len=strlen(s[0]+1),fst=0,last,hs[2][2]={0,0,0,0},ans=0;
        for(int c=1;c<=len;c++){
            if(s[0][c]!=s[1][c]){
                if(!fst)fst=c;
                last=c;
            }
        }
        h[0][last]=h[1][last]=0;
        for(int c=last+1;c<=len;c++)for(int d=0;d<2;d++)h[d][c]=(h[d][c-1]*base[d][1]+s[0][c])%mod[d];
        for(int c=last;c;c--){
            for(int d=0;d<2;d++)for(int e=0;e<2;e++)hs[d][e]=(hs[d][e]+s[d][c]*base[e][last-c])%mod[e];
            if(c<=fst && id[{hs[0][0]*mod[1]+hs[0][1],hs[1][0]*mod[1]+hs[1][1]}])ans=ans+ask(id[{hs[0][0]*mod[1]+hs[0][1],hs[1][0]*mod[1]+hs[1][1]}],last+1,len+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}