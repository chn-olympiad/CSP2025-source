#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<ull,ull>
using namespace std;
const int N=5e6+100;
int n,m,len[N],p1[N],p2[N];
string s1,s2;
ull p[N],hsh1[N],hsh2[N];
pii mp[N];
inline int in(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') k=(k<<3)+(k<<1)+c-'0',c=getchar();
    return k*f;
}
ull get1(int l,int r){
    return hsh1[r]-hsh1[l-1]*p[r-l+1];
}
ull get2(int l,int r){
    return hsh2[r]-hsh2[l-1]*p[r-l+1];
}
void slove_1(){
    cin>>s1>>s2;
    int len1=s1.size(),len2=s2.size();
    s1=' '+s1;
    s2=' '+s2;
    if(len1!=len2)
    {
        printf("0\n");
        return;
    }
    for(int i=1;i<=len1;i++)
    hsh1[i]=hsh1[i-1]*13331+s1[i]-'a'+1;
    for(int i=1;i<=len2;i++)
    hsh2[i]=hsh2[i-1]*13331+s2[i]-'a'+1;
    int ans=0;
    for(int i=1;i<=len1;i++)
    {
        for(int x=1;x<=n;x++)
        {
            if(i<len[x]) continue;
            if(get1(i-len[x]+1,i)==mp[x].first&&hsh1[i]-mp[x].first+mp[x].second==hsh2[i]&&get1(i+1,len1)==get2(i+1,len2))
            ans++;
        }
    }
    printf("%lld\n",ans);
}
void slove1(){
    p[0]=1;
    for(int i=1;i<=5e6;i++)
    p[i]=p[i-1]*13331;
    for(int j=1;j<=n;j++)
    {
        cin>>s1>>s2;
        int len1=s1.size(),len2=s2.size();
        s1=' '+s1;
        s2=' '+s2;
        ull hs=0;
        for(int i=1;i<=len1;i++)
        hs=hs*13331+s1[i]-'a'+1;
        ull now=hs;
        hs=0;
        for(int i=1;i<=len2;i++)
        hs=hs*13331+s2[i]-'a'+1;
        mp[j]=make_pair(now,hs);
        len[j]=len1;
    }
    for(int i=1;i<=m;i++)
    slove_1();
}
void slove_2(){
    cin>>s1>>s2;
    int len1=s1.size(),len2=s2.size();
    s1=' '+s1;
    s2=' '+s2;
    if(len1!=len2)
    {
        printf("0\n");
        return;
    }
    int pos1=0,pos2=0;
    for(int i=1;i<=len1;i++)
    {
        if(s1[i]=='b') pos1=i;
        if(s2[i]=='b') pos2=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    if(p1[i]-p2[i]==pos1-pos2&&pos1>=p1[i]&&pos2>=p2[i]&&len1-pos1>=len[i]-p1[i]&&len1-pos2>=len[i]-p2[i]) 
    ans++;
    printf("%lld\n",ans);
}
void slove2(){
    for(int j=1;j<=n;j++)
    {
        cin>>s1>>s2;
        int len1=s1.size(),len2=s2.size();
        s1=' '+s1;
        s2=' '+s2;
        for(int i=1;i<=len1;i++)
        {
            if(s1[i]=='b') p1[j]=i;
            if(s2[i]=='b') p2[j]=i;
        }
        len[j]=len1;
    }
    for(int i=1;i<=m;i++)
    slove_2();
}
signed main(){
    freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
    n=in(),m=in();
    if(n<=1e3) slove1();
    else slove2();
    return 0;
}