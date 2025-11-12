#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=2e5+5,M=5e6+5;
const ull P=13331;
int n,m;
char a[M],b[M];
ull h[2][M],p[M];

vector<char> s[N][2];

inline int read(){
	int x=0;
	char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x;
}

map<pair<ull,ull>,int> Map; 

int get(int l,int r,int t){
	return h[t][r]-h[t][l-1]*p[r-l+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",a,b);
		int len=strlen(a);
		s[i][0].resize(len),s[i][1].resize(len);
		ull h1=0,h2=0;
		for(int j=0;j<len;j++){
			s[i][0][j]=a[j],s[i][1][j]=b[j]; 
			h1=h1*P+a[j]-'a';
			h2=h2*P+b[j]-'a';
		}
		Map[make_pair(h1,h2)]++;
	} 
	while(m--){
		scanf("%s%s",a+1,b+1);
		int len=strlen(a+1);
		if(len!=(int)strlen(b+1)){
			puts("0");
			continue;
		}
		p[0]=1;
		for(int i=1;i<=len;i++){
			h[0][i]=h[0][i-1]*P+a[i]-'a';
			h[1][i]=h[1][i-1]*P+b[i]-'a';
			p[i]=p[i-1]*P;
		}
		int l=1,r=len;
		while(a[l]==b[l]) l++;
		while(a[r]==b[r]) r--;
		ll ans=0;
		for(int i=1;i<=l;i++){
			for(int j=r;j<=len;j++){
				if(Map.count(make_pair(get(i,j,0),get(i,j,1)))) ans+=Map[make_pair(get(i,j,0),get(i,j,1))];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
