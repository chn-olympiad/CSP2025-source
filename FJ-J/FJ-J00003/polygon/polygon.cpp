#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int maxn=5005;
int read(){
	bool f=0;char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch=='-')f=1;
	int x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
ll ksm(int b){
	if(b==1)return 2;
	if(b==0)return 1;
	if(b%2==0){ll k=ksm(b/2)%mod;return k*k%mod; }
	if(b%2==1)return 2*(ksm(b-1)%mod);
}
bool cmp(int b,int c){return b>c;}
int n;
int a[maxn];
unsigned ll ans;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int hcyd=a[i]-a[j];//
			int r=j+1,l=n;
			while(r<l){
				int mid=(l+r)>>1;
				if(a[mid]>=hcyd)r=mid+1;
				else l=mid;
			}
			if(l>n)continue;
			//printf("%d %d %d %d %d %lld\n",n==r?1:0,n,n-j+1,r,n-r,ksm(n-j)-ksm(n-r+1));
			ans=(ans+(ll)(ksm(n-j)%mod-ksm(n-l)%mod)%mod)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
//O(n^2 log n)
//二分忘记了:|
 
