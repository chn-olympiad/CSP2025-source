#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10, M = 20; 
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans,c[N],b[N],fail,cnt;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	if (n>=12){
		cout << 0;
		return 0; 
	}	
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		c[i]=read();		
		b[i]=i;
	}
	do{
		fail=0,cnt=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='0') fail++;
			else if (fail>=c[b[i]]) fail++;
			else cnt++;
		}
		//cout << cnt << "\n";
		if (cnt>=m) ans++;
	}while (next_permutation(b+1,b+n+1));
	cout << ans;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
