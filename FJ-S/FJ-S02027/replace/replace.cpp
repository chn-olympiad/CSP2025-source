#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(long long i=a;i<=b;i++)
#define dlp(i,b,a) for(long long i=b;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int l,r;
pair<string ,string> st[200005];
pair<int,int> plic[200005];
string x,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	ulp(i,1,n){
		string sp1,sp2;
		cin>>sp1,sp2;
		
		st[i].first=sp1;st[i].second=sp2;
		while(st[i].second[plic[i].second]=='a')++plic[i].second;
		while(st[i].first[plic[i].first]=='a')++plic[i].first;
	}
	while(q--){
		cin>>x>>y;
		l=0,r=0;
		while(x[l]=='a')++l;
		while(x[r]=='a')++r;
		int ans=0;
		ulp(i,1,n){
			if(plic[i].second+(l-plic[i].first)==r){
				if(st[i].first.size()-1+(l-plic[i].first)>=st[i].first.size()||plic[i].first<l||plic[i].second<r||st[i].second.size()-1+(r-plic[i].second)>=st[i].second.size()){
					continue;
				}
				else{
					ans++;
				}
			}
		}
		write(ans);
		puts("");
	}
}
