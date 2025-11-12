#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[24];int tot=0;
	do{stk[++tot]=x%10+48;x/=10;}while(x);
	for(;tot;)putchar(stk[tot--]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
const int maxL=5e6+4,maxn=2e5+4;const unsigned long long base=19491001;int n,q;char s[maxL],t[maxL];
// std::map<std::pair<unsigned long long,unsigned long long>,int>mp[3500];
std::unordered_map<unsigned long long,int>mp[3500];
std::pair<unsigned long long,unsigned long long>a[maxn];int b[maxn],tot,len[maxn];
unsigned long long pres[maxL],pret[maxL],pw[maxL];
unsigned long long gets(int l,int r){return pres[r]-pres[l-1]*pw[r-l+1];}
unsigned long long gett(int l,int r){return pret[r]-pret[l-1]*pw[r-l+1];}
unsigned long long get(std::pair<unsigned long long,unsigned long long>x){return (x.first*base)^x.second;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n,q);pw[0]=1;
    for(int i=1;i<=5000000;++i)pw[i]=pw[i-1]*base;
    for(int i=1;i<=n;++i){
        scanf("%s%s",s+1,t+1);len[i]=strlen(s+1);b[i]=len[i];
        for(int j=1;j<=len[i];++j)a[i].first=a[i].first*base+s[j];
        for(int j=1;j<=len[i];++j)a[i].second=a[i].second*base+t[j];
    }
    std::sort(b+1,b+n+1);tot=std::unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;++i){
        int x=std::lower_bound(b+1,b+tot+1,len[i])-b;
        mp[x][get(a[i])]++;
        // mp[x][a[i]]++;
        // write(len[i],' ',x,':',a[i].first,' ',a[i].second,'\n');
    }
    for(;q--;){
        scanf("%s%s",s+1,t+1);int len=strlen(s+1);
        if(strlen(t+1)!=len){write(0,'\n');continue;}
        for(int i=1;i<=len;++i)pres[i]=pres[i-1]*base+s[i];
        for(int i=1;i<=len;++i)pret[i]=pret[i-1]*base+t[i];
        int l=1,r=len;
        for(;l<=len&&s[l]==t[l];l++);
        for(;r>=1&&s[r]==t[r];r--);
        long long ans=0;
        for(int i=1;i<=tot;++i){
            int j=b[i];
            for(int k=std::max(1,r-j+1);k<=l&&k+j-1<=len;++k){
                // write(i,' ',j,' ',k,':',gets(k,k+j-1),' ',gett(k,k+j-1),'\n');
                // ALL++;
                ans+=mp[i][get(std::make_pair(gets(k,k+j-1),gett(k,k+j-1)))];
                // ans+=mp[i][std::make_pair(gets(k,k+j-1),gett(k,k+j-1))];
            }
        }
        write(ans,'\n');
    }
	return 0;
}