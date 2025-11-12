#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1; char c=0;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
const int N=1e6+10;
int n;
int a[N][3],cnt[3];
int fir[N],id[N],sec[N];
int b[N];
inline void solve(){
	n=read();
	cnt[0]=cnt[1]=cnt[2]=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		fir[i]=a[i][0],id[i]=0;
		sec[i]=0;
		if(a[i][1]>a[i][0]) sec[i]=fir[i],fir[i]=a[i][1],id[i]=1;
		else sec[i]=a[i][1];
		if(a[i][2]>fir[i]) sec[i]=fir[i],fir[i]=a[i][2],id[i]=2;
		else if(a[i][2]>sec[i]) sec[i]=a[i][2];
		cnt[id[i]]++;
		sum+=fir[i];
	}
	int rid=-1;
	if(cnt[0]>n/2) rid=0;
	if(cnt[1]>n/2) rid=1;
	if(cnt[2]>n/2) rid=2;
	if(rid==-1) printf("%lld\n",sum);
	else{
		int tot=0;
		for(int i=1;i<=n;i++){
			if(id[i]==rid) b[++tot]=fir[i]-sec[i];
		}
		sort(b+1,b+tot+1);
		tot=cnt[rid]-n/2;
		for(int i=1;i<=tot;i++) sum-=b[i];
		printf("%lld\n",sum);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--) solve();
	return 0;
}