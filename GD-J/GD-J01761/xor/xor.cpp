#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=5e5+10;
const int mx=7e7+5e5+10;
int k;
int a[maxn];
int tot;
int n,m;
int qzh[maxn];
int r;
struct abc{
	int x,y;
	bool operator < (const abc&o){
		if(y!=o.y) return y<o.y;
		else return x>o.x;
	}
}st[mx];
long long ans;
int cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i = 1;i <= n;i++){
		qzh[i]=qzh[i-1];
		scanf("%lld",&a[i]);
		qzh[i]^=a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int l = 1,r = i;r <= n;l++,r++){
			if((qzh[r]^qzh[l-1])==k){
				st[++tot]={l,r};
//				cnt++;
			}
			
		}
	}
	sort(st+1,st+tot+1);
	for(int i = 1;i <= tot;i++){
		if(st[i].x>r){
			r=st[i].y;
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
} 
