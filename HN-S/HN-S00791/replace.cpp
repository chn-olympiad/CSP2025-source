#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define ull unsigned long long
#define max3(a,b,c) max(a,max(b,c))
#define fi first
#define se second

using namespace std;
const int N=2e5+5;
const int M=5e6+5;
string xs[N],ys[N];
inline int in(){
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0'; c=getchar();
	}return s*w;
}
int n,q;
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>xs[i]>>ys[i];
	}
	while(q--){
		string s,s1;
		cin>>s>>s1;
		int l,r,ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=s1[i]) {
				l=i;break;
			}
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]!=s1[i]){
				r=i;break;
			}
		}
		int len=r-l+1;
		string h,h1;
		for(int i=l;i<=r;i++){
			h+=s[i];h1+=s1[i];
		}
		for(int i=1;i<=n;i++){
			if(xs[i]==s&&ys[i]==s1) ans++;
			if(xs[i]==h&&ys[i]==h1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
