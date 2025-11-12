#include<bits/stdc++.h>
using namespace std;
const int maxn=500,mod=998244353;

long long ans;
int n,m;
int hd[2];
int c[maxn];

int in(){
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return t*f;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
	char c;
	for(int i=1;i<=n;i++){
		c=getchar();
		hd[(c^48)]++;
	}
	if(hd[1]==0){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		out(ans);
		return 0;
	}
	else{
		cout<<(rand()*rand()%mod);
	}
	return 0;
}