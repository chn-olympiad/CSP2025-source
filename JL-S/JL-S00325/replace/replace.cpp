#include<bits/stdc++.h>
using namespace std;

int n,Q,ans;
int len[50010][3],len1,len2;
char s[5010][3][5010];
char t[3][250010];
int de[50010],p[50010],q[50010];

inline void subB(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=len[i][1];j++) if(s[i][1][j]=='b') p[i]=j;
        for(int j=1;j<=len[i][2];j++) if(s[i][2][j]=='b') q[i]=j;
        de[i]=p[i]-q[i];
        //cout<<p[i]<<' '<<q[i]<<' '<<de[i]<<endl;
    }
    int x,y;
    while(Q--){
        ans=0;
        scanf("%s%s",t[1]+1,t[2]+1);
        len1=strlen(t[1]+1);len2=strlen(t[2]+1);
        for(int j=1;j<=len1;j++) if(t[1][j]=='b') x=j;
        for(int j=1;j<=len2;j++) if(t[2][j]=='b') y=j;
        //cout<<x<<' '<<y<<' '<<x-y<<endl;
        for(int i=1;i<=n;++i){
            if(x-y==de[i] && x-1>=p[i]-1 && len1-x>=len[i][1]-p[i] && len1-len[i][1]+len[i][2]==len2) ans++;
        }
        printf("%d\n",ans);
    }
}

inline void suba(){
    while(Q--){
        ans=0;
        scanf("%s%s",t[1]+1,t[2]+1);
        len1=strlen(t[1]+1);len2=strlen(t[2]+1);
        for(int i=1;i<=len1;++i){
            bool match=true;
            for(int id=1;id<=n;++id){
                match=true;
                for(int j=1;j<=len[id][1];++j){
                    if(s[id][1][j]!=t[1][i+j-1]){
                        match=false;
                        break;
                    }
                }
                if(match && len[id][2]+len1-len[id][1]==len2){
                    match=true;
                    for(int p=1;p<i;p++){
                        if(t[1][p]!=t[2][p]){
                            match=false;
                            break;
                        }
                    }
                    if(!match) continue;
                    for(int p=1;p<=len[id][2];++p){
                        if(t[2][p+i-1]!=s[id][2][p]){
                            match=false;
                            break;
                        }
                    }
                    if(!match) continue;
                    for(int p=i+len[id][1];p<=len1;++p){
                        if(t[2][p-len[id][1]+len[id][2]]!=t[1][p]){
                            match=false;
                            break;
                        }
                    }
                }
                if(len[id][2]+len1-len[id][1]!=len2) match=false;
                if(match) ans++;
            }
        }printf("%d\n",ans);
    }
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;++i){
        scanf("%s%s",s[i][1]+1,s[i][2]+1);
        len[i][1]=strlen(s[i][1]+1);
        len[i][2]=strlen(s[i][2]+1);
    }
    if(n<=1000) suba();
    else subB();
    return 0;
}
