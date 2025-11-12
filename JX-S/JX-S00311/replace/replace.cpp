#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
const int maxn=205;
char c[maxn][2][maxn];
char s[2][maxn];
int len[maxn];
ll ans;
bool ch(int x,int pos,int lenx){
    for(int i=1;i<pos;i++){
        if(s[0][i]==s[1][i]){

        }
        else return false;
    }
    for(int i=pos;i<pos+len[x];i++){
        if(s[0][i]==c[x][0][i-pos+1]&&s[1][i]==c[x][1][i-pos+1]){

        }
        else return false;
    }
    for(int i=pos+len[x];i<=lenx;i++){
        if(s[0][i]==s[1][i]){

        }
        else return false;
    }
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",c[i][0]+1,c[i][1]+1);
        len[i]=strlen(c[i][0]+1);
    }
    while(q--){
        ans=0;
        scanf("%s%s",s[0]+1,s[1]+1);
        int lenx=strlen(s[0]+1);
        for(int i=1;i<=n;i++){
            for(int pos=1;pos<=lenx-len[i]+1;pos++){
                if(ch(i,pos,lenx))ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
