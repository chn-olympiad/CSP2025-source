#include<bits/stdc++.h>
#define int long long 
#define fast register int
using namespace std;
const int maxn=1e6+5;

string s;
int a[maxn],len,k;

bool cmp(int x,int y){
	return x>y;
}

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(fast i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') a[++k]=s[i]-'0';
	}
	sort(a+1,a+k+1,cmp);
	for(fast i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}