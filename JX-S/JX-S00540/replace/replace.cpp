#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define cin std::cin
#define cout std::cout
inline void printt(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) printt(x/10);
	putchar(x%10+'0');
}
inline void print(int x){
	printt(x);
	puts("");
}
inline int read(){
	char c;
	int res=0,flag=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			flag=-1;
			c=getchar();
			break;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
const int N=2e5+1;
int n,q,fg=0,l1[N],r1[N],l2[N],r2[N];
std::map<std::string,std::string> mp;
std::vector<std::pair<int,int>> s;
std::string s1[N],s2[N],t1,t2;
inline void solve(){
	int ans=0;
	//wcnm,sbccf
	print(ans);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
		mp[s2[i]]=s1[i];
		int len=s1[i].length(),cnta=0,cntb=0;
		for(int j=0;j<len;j++){
			if(s1[i][j]=='a') cnta++;
			if(s1[i][j]=='b') cntb++;
			if(s2[i][j]=='a') cnta++;
			if(s2[i][j]=='b') cntb++;
		}
		if(cnta+cntb==len*2) fg++;
	}
	if(fg==n){
		for(int i=1;i<=n;i++){
			bool fg1=0,fg2=0;
			int ps1,ps2,len=s1[i].length();
			for(int j=0;j<len;j++){
				if(fg1&&fg2) break;
				if(t1[j]=='b') ps1=j,fg1=1;
				if(t2[j]=='b') ps2=j,fg2=1;
			}
			l1[i]=ps1-1,r1[i]=n-ps1;
			l2[i]=ps2-1,r2[i]=n-ps2;
		}
	}
	while(q--){
		s.clear();
		cin>>t1>>t2;
		int ans=0,len=t1.length();
		if(fg==n){
			if(t1.length()!=t2.length()){puts("0");continue;}
			bool fg1=0,fg2=0;
			int ps1,ps2;
			for(int i=0;i<len;i++){
				if(fg1&&fg2) break;
				if(t1[i]=='b') ps1=i,fg1=1;
				if(t2[i]=='b') ps2=i,fg2=1;
			}
			for(int i=1;i<=n;i++){
				if(l1[i]<=ps1-1&&r1[i]<=n-ps1&&l2[i]<=ps2-1&&r2[i]<=n-ps2) ans++;
			}
			print(ans);
		}else{
			if(t1.length()!=t2.length()){puts("0");continue;}
			for(int i=0;i<len;i++){
				if(t1[i]==t2[i]) continue;
				int l=i;
				while(t1[i]!=t2[i]) i++;
				s.push_back(std::make_pair(l,i-1));
			}
			bool flag=0;
			if(s.size()>1){
				for(int i=1;i<=n;i++){
					if(s1[i]==t1&&s2[i]==t2){
						puts("1");
						flag=1;
						break;
					}
				}
				if(!flag){puts("0");continue;}
			}else solve();
		}
	}
	return 0;
}
