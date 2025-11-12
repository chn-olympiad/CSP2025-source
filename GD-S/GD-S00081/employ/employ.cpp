#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb emplace_back
#define fr first
#define sc second
typedef const int Int;
typedef pair<int,int> pii;

inline  Int read(){
	int x=0;char c=getchar();bool f=(c=='-');
	while(!isdigit(c))c=getchar(),f|=(c=='-');
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}

Int N=505;

int n,m;

bool b[N];

string s;

int c[N];

int idx[N];

int ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	int tot=0;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)idx[i]=i;
	for(int i=0;i<s.size();i++)b[i+1]=s[i]-'0',tot+=b[i];
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)if(cnt>=c[idx[i]]||!b[i])cnt++;
		ans+=(n-cnt>=m);
	}while(next_permutation(idx+1,idx+1+n));
	printf("%d",ans);
	return 0;
}



































