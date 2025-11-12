#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int N = 1e6+5;
const ll mod = 1e9+7,P=131;
int n,q,al[N];
char s1[N],s2[N];
ll hs1[N],hs2[N],pw[N];
struct Node{
    int len;ll hs1,hs2;
}a[N];

ll geths1(int l,int r){return ((hs1[r]-hs1[l-1]*pw[r-l+1]%mod)%mod+mod)%mod;}
ll geths2(int l,int r){return ((hs2[r]-hs2[l-1]*pw[r-l+1]%mod)%mod+mod)%mod;}
bool cmp(Node a,Node b){return a.len<b.len;}

void work(){pw[0]=1;ll ans=0;
    scanf("%s",s1+1);scanf("%s",s2+1);int len=strlen(s1+1),sbl=strlen(s2+1);int l=0,r=len+1;
    if(len!=sbl)return puts("0"),void();
    for(int i=1;i<=len;i++)if(s1[i]==s2[i])l=i;else break;
    for(int i=len;i>=1;i--)if(s1[i]==s2[i])r=i;else break;
    for(int i=1;i<=len;i++){
        hs1[i]=(hs1[i-1]*P%mod+s1[i])%mod;
        hs2[i]=(hs2[i-1]*P%mod+s2[i])%mod;
        pw[i]=pw[i-1]*P%mod;
    }
    for(int i=0;i<=l;i++){
        int jj=lower_bound(al+1,al+1+n,r-1-(i+1)+1)-al;//cerr<<i<<" "<<jj<<endl;
        for(int j=jj;j<=n;j++){
            if(i+a[j].len+1>=r&&i+a[j].len<=len){
                if(geths1(i+1,i+a[j].len)==a[j].hs1&&geths2(i+1,i+a[j].len)==a[j].hs2)ans++;
                // cerr<<i+1<<" "<<i+a[j].len<<" "<<j<<endl;
                // cerr<<geths1(i+1,i+a[j].len)<<" "<<a[j].hs1<<endl;
                // cerr<<geths2(i+1,i+a[j].len)<<" "<<a[j].hs2<<endl;
                if(i+a[j].len>len)break;
            }
        }
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    n=read(),q=read();for(int i=1,len;i<=n;i++){
        scanf("%s",s1+1);scanf("%s",s2+1);len=strlen(s1+1);
        ll hs1_=0,hs2_=0;for(int j=1;j<=len;j++){
            hs1_=(hs1_*P%mod+s1[j])%mod;
            hs2_=(hs2_*P%mod+s2[j])%mod;
        }a[i]=Node{len,hs1_,hs2_};
    }sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)al[i]=a[i].len;
    while(q--)work();
    return 0;
}