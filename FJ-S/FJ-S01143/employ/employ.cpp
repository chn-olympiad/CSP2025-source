#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> PII;

int read() {
	int n=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		n=(n<<1)+(n<<3)+ch-'0';
		ch=getchar();
	}
	return f==1?n:-n;
}

void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//===========================================//

const int N=507;
const ll MOD=998244353;

int n,m;
char s[N];
int c[N];

//===========================================//

namespace Subtask1{
	
	bool check() {
		return n<=10;
	}
	
	int p[N];
	
	void Main() {
		for(int i=1;i<=n;i++) 
			p[i]=i;
		int ans=0;
		do{
			int t=0;
			for(int i=1;i<=n;i++) {
				int j=p[i];
				if((i-1)-t>=c[j]) continue;
				if(s[i]=='0') continue;
				t++;
			} 
			if(t>=m) ans++;
		}while(next_permutation(p+1,p+1+n));
		write(ans);
	}
	
};

//===========================================//

namespace Subtask2{
	
	bool check() {
		return m==n;
	}
	
	void Main() {
		for(int i=1;i<=n;i++) 
			if(c[i]==0) {
				write(0);
				return;
			}
		for(int i=1;i<=n;i++) 
			if(s[i]=='0') {
				write(0);
				return;
			}
		ll ans=1;
		for(int i=2;i<=n;i++) 
			ans=ans*i%MOD;
		write(ans);
	}
	
};

//===========================================//

void input() {
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) 
		c[i]=read();
}

void work() {
	if(Subtask2::check()) {
		Subtask2::Main();
		return;
	}
	if(Subtask1::check()) {
		Subtask1::Main();
		return;
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	input();
	work();
	return 0;
}
