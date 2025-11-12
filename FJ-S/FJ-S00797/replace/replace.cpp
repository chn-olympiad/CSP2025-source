#include<bits/stdc++.h>
const int N=6e6;
int n,qe;
char s[2][N+5];
int lcs,lcp;
void get(int le){
    lcp=le;
    for(int i=1;i<=le;++i)if(s[0][i]!=s[1][i]){
        lcp=i-1;
        break;
    }
    lcs=le;
    for(int i=le;i;--i)if(s[0][i]!=s[1][i]){
        lcs=le-i;
        break;
    }
}
int tr[N+5][27],cnt,h[N+5];
int vv[N+5];
int sn[N+5][27],lk[N+5];
void inst(int le){
    int u=1;
    for(int i=lcp+1;i<=le-lcs;++i){
        int c=s[0][i]-'a';
        if(!tr[u][c])tr[u][c]=++cnt;
        u=tr[u][c];
    }
    for(int i=lcp+1;i<=le-lcs;++i){
        int c=s[1][i]-'a';
        if(!tr[u][c])tr[u][c]=++cnt;
        u=tr[u][c];
    }
    vv[u]=1;
    //printf("%d ",u);
    for(int i=1;i<=lcp;++i){
        int c=s[0][i]-'a';
        if(!sn[u][c])sn[u][c]=++cnt;
        u=sn[u][c];
    }
    int c=26;
    if(!sn[u][c])sn[u][c]=++cnt;
    u=sn[u][c];
    for(int i=le-lcs+1;i<=le;++i){
        int c=s[0][i]-'a';
        if(!sn[u][c])sn[u][c]=++cnt;
        u=sn[u][c];
    }
    ++h[u];
}
int vsc[N+5];
int z[N+5],tot;
int q[N+5],head,tail;
void getAC(int rt){
    //printf("%d\n",rt);
    lk[rt]=rt;
    head=tail=0;
    for(int i=0;i<=26;++i){
        if(!sn[rt][i])sn[rt][i]=rt;
        else q[tail++]=sn[rt][i];
        lk[sn[rt][i]]=rt;
    }
    while(head!=tail){
        int u=q[head++];
        h[u]+=h[lk[u]];
        for(int j=0;j<=26;++j){
            //printf("%d %d\n",u,sn[u][j]);
            if(sn[u][j])lk[sn[u][j]]=sn[lk[u]][j],q[tail++]=sn[u][j];
            else sn[u][j]=sn[lk[u]][j];
        }
    }
}
void getans(int le){
    int u=1;
    for(int i=lcp+1;i<=le-lcs;++i){
        int c=s[0][i]-'a';
        u=tr[u][c];
    }
    for(int i=lcp+1;i<=le-lcs;++i){
        int c=s[1][i]-'a';
        u=tr[u][c];
    }
    int ss=0;
    for(int i=1;i<=lcp;++i){
        int c=s[0][i]-'a';
        u=sn[u][c];
        //int x=u;
        //s+=h[u];
    }
    int c=26;
    u=sn[u][c];
    ss+=h[u];
    for(int i=le-lcs+1;i<=le;++i){
        int c=s[0][i]-'a';
        u=sn[u][c];
        ss+=h[u];
    }
    printf("%d\n",ss);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&qe);
    ++cnt;
    for(int i=1;i<=n;++i){
        scanf("%s%s",s[0]+1,s[1]+1);
        int le=strlen(s[0]+1);
        get(le);
        if(lcp!=le)inst(le);
    }
    for(int i=1;i<=cnt;++i)if(vv[i]){
        getAC(i);
    }
    for(int i=1;i<=qe;++i){
        scanf("%s%s",s[0]+1,s[1]+1);
        int le=strlen(s[0]+1),le1=strlen(s[1]+1);
        if(le!=le1){
            printf("0\n");
            continue;
        }
        get(le);
        getans(le);
    }
    //while(1);
    return 0;
}