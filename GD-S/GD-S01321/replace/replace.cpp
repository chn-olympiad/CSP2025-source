#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=2e5+10;

int n,q;
string s[N][3];
int len[N][3];

string t[3];

int main(){
	freopen("replace.in","r",stdin);
	// freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        char ch=getchar();
        s[i][1]+=".",s[i][2]+=".";
        while(ch<'a' || ch>'z'){ch=getchar();}
        while(ch>='a' && ch<='z'){s[i][1]+=ch;++len[i][1];ch=getchar();}
        while(ch<'a' || ch>'z'){ch=getchar();}
        while(ch>='a' && ch<='z'){s[i][2]+=ch;++len[i][2];ch=getchar();}

        // cout<<s[i][1]<<" "<<s[i][2]<<"\n";
    }
    
    for(int i=1;i<=q;i++){
        int ans=0;
        int l1=0,l2=0;
        t[1]="",t[2]="";
        t[1]+=".";
        t[2]+=".";
        char ch=getchar();
        while(ch<'a' || ch>'z'){ch=getchar();}
        while(ch>='a' && ch<='z'){t[1]+=ch;l1++;ch=getchar();}
        while(ch<'a' || ch>'z'){ch=getchar();}
        while(ch>='a' && ch<='z'){t[2]+=ch;l2++;ch=getchar();}
        // cout<<t[1]<<" "<<t[2]<<"\n";
        for(int j=1;j<=n;j++){
            if(!(len[j][1]<=l1)) continue;
            for(int k=1;k+len[j][1]-1<=l1;k++){
                bool p=1;
                for(int t1=k,t2=1;t1<=k+len[j][1]-1;t1++,t2++){
                    if(t[1][t1]!=s[j][1][t2]){
                        p=0;
                        break;
                    }
                }
                if(p){
                    string tmp=t[1];
                    for(int t1=k;t1<=k+len[j][1]-1;t1++){
                        tmp[t1]=s[j][2][t1-k+1];
                    }
                    bool fg=1;
                    for(int pp=1;pp<=l1;pp++){
                        if(tmp[pp]!=t[2][pp]){
                            fg=0;
                            break;
                        }
                    }
                    if(fg){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
