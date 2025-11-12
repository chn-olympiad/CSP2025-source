#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<ll,ll> PII;

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

const int N=1e5+7;

int n;
ll a[N][4];

priority_queue<ll,vector<ll>,less<ll> > q[4];
ll ans;

//===========================================//

void input() {
	n=read();
	for(int i=1;i<=n;i++) 
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
}

void work() {
	ans=0;
	while(q[1].size()) q[1].pop();
	while(q[2].size()) q[2].pop();
	while(q[3].size()) q[3].pop();
	for(int i=1;i<=n;i++) {
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) {
			q[1].push(max(a[i][2],a[i][3])-a[i][1]),ans+=a[i][1];
			if(q[1].size()>n/2) ans+=q[1].top(),q[1].pop();
		}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) {
			q[2].push(max(a[i][1],a[i][3])-a[i][2]),ans+=a[i][2];
			if(q[2].size()>n/2) ans+=q[2].top(),q[2].pop();
		}else{
			q[3].push(max(a[i][1],a[i][2])-a[i][3]),ans+=a[i][3];
			if(q[3].size()>n/2) ans+=q[3].top(),q[3].pop();
		}	
	}
	write(ans),putchar('\n');
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) {
		input();
		work();
	}
	return 0;
}
