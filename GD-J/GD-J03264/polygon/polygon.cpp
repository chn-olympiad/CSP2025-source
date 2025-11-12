#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e3+10,MOD=998244353;

int n,cnt=0,maxn=0,ans=0;
int s[MAXN],invs[MAXN];

void exgcd(long long a,long b,long long &x,long long &y){
	if (!b){
		x=1l,y=0l;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

void init(){
	s[0]=1;
	for (int i=1;i<=n;i++)
		s[i]=1ll*s[i-1]*i%MOD;
	long long x,y;
	exgcd(s[n],MOD,x,y);
	invs[n]=(x+MOD)%MOD;
	for (int i=n-1;i>=0;i--)
		invs[i]=1ll*invs[i+1]*(i+1)%MOD;
}

int C(int x,int y){
	return 1ll*s[x]*invs[y]%MOD*invs[x-y]%MOD;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[MAXN];
	cin >>n;
	init();
	for (int i=1;i<=n;i++){
		cin >>a[i];
		cnt+=a[i],maxn=max(maxn,a[i]);
	}
	if (maxn==1){
		for (int i=3;i<=n;i++)
			ans=(1ll*ans+C(n,i))%MOD;
		cout <<ans <<'\n';
		return 0;
	}
	if (cnt>2*maxn) cout <<"1\n";
	else cout <<"0\n";
	return 0;
}
