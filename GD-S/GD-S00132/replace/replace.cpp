#include<bits/stdc++.h>
// #define int long long
#define FILE(str) freopen(str".in","r",stdin),freopen(str".out","w",stdout)
inline void read(int &x){
    x=0;int f(1);
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    x=x*f;
}
#define pb push_back
using vi=std::vector <int>;
using pii=std::pair <int,int>;
using str=std::string;
const int MAXN=2e5+5;
int n,q;
str s[MAXN][2];
int l[MAXN],r[MAXN];
std::map <std::pair<str,str>,std::vector<int> > arr;
signed main(){
    FILE("replace");
    read(n),read(q);
    for(int i=1;i<=n;i++){
        std::cin>>s[i][0]>>s[i][1];
        l[i]=0,r[i]=s[i][0].length()-1;
        while(l[i]<s[i][0].length()&&s[i][0][l[i]]==s[i][1][l[i]]) ++l[i];
        while(r[i]!=-1&&s[i][0][r[i]]==s[i][1][r[i]]) --r[i];
        arr[{s[i][0].substr(l[i],std::max(r[i]-l[i]+1,0)),s[i][1].substr(l[i],std::max(r[i]-l[i]+1,0))}].emplace_back(i);
    }
    while(q--){
        int ans(0);
        str t[2];
        std::cin>>t[0]>>t[1];
        if(t[0].length()!=t[1].length()){
            puts("0");
            continue;
        }        
        int L=0,R=t[0].length()-1;
        while(L<t[0].length()&&t[0][L]==t[1][L]) ++L;
        while(R!=-1&&t[0][R]==t[1][R]) --R;
        for(auto it:arr[{t[0].substr(L,std::max(R-L+1,0)),t[1].substr(L,std::max(R-L+1,0))}]){
            if(l[it]>L||s[it][0].length()-r[it]>t[0].length()-R) continue;
            int i=l[it]-1,j=L-1;
            while(i!=-1&&s[it][0][i]==t[0][j]) --i,--j;
            if(i!=-1) continue;
            i=r[it]+1,j=R+1;
            while(i<s[it][0].length()&&s[it][0][i]==t[0][j]) ++i,++j;
            if(i!=s[it][0].length()) continue;
            ++ans;
        }
        printf("%d\n",ans);
    }
}