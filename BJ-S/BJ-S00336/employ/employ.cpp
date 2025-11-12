#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
// bool mst;
char st[N];int n,m,a[N];
namespace sol1{
int f[1<<18][19][19];
inline void upd(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
void main(){
	f[0][0][0]=1;int all=(1<<n);
	for(int s=0;s+1<all;s++){
		int pos=__builtin_popcount(s)+1;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			if(!f[s][i][j])	continue;
			for(int x=1;x<=n;x++)if(!(s>>x-1&1)){
				if(st[pos]=='0'||i>=a[x])	upd(f[s|(1<<x-1)][i+1][j],f[s][i][j]);
				else	upd(f[s|(1<<x-1)][i][j+1],f[s][i][j]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)for(int j=m;j<=n;j++)upd(ans,f[all-1][i][j]);
	cout<<ans;
}
}
namespace sol2{
int c[N];
void main(){
	int ans=1,res=1,cnt=0;
	for(int i=1;i<=n;i++)	c[a[i]]++;
	for(int i=1;i<=n;i++)	c[i]+=c[i-1];
	for(int i=1;i<=n;i++)	ans=1ll*ans*i%mod;
	for(int i=1;i<=n;i++)if(st[i]=='1'){
		if(c[i]>cnt)	res=1ll*res*(c[i-1]-cnt)%mod;
		else	res=0;
		cnt++;
	}
	for(int i=cnt;i<n;i++)	res=1ll*res*(n-i)%mod;
	cout<<(ans-res+mod)%mod;
}
}
namespace sol3{
void main(){
	bool flag=1;
	for(int i=1;i<=n;i++)flag&=(st[i]=='1');
	for(int i=1;i<=n;i++)flag&=(a[i]!=0);
	if(flag){
		int ans=1;
		for(int i=1;i<=n;i++)	ans=1ll*ans*i%mod;
		cout<<ans;
	}else	cout<<0;
}
}
// bool med;
int main(){
	// cerr<<fabs(&mst-&med)/1024.0/1024<<'\n';
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>st+1;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=18)	sol1::main();
	else if(m==1)	sol2::main();
	else if(m==n)	sol3::main();
	else	cout<<0;
	return 0;
}
