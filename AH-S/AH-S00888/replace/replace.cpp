#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N=5000000,base=131;
char s[2][N+5],t[2][N+5];
int n,m,k,l[N+5];
unsigned long long p[N+5],tmp;
unsigned long long hsh[2][N+5];
unsigned long long Hash(int x,int l,int r){
	return hsh[x][r]-hsh[x][l-1]*p[r-l+1];
}
int mn,mx,ans;
unordered_map<unsigned long long,int>mp[N+5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0,len;i<n;++i){
		cin>>(s[0]+1)>>(s[1]+1);
		len=strlen(s[0]+1);
		tmp=0;
		for(int j=1;j<=len;++j)tmp=tmp*base+s[0][j];
		for(int j=1;j<=len;++j)tmp=tmp*base+s[1][j];
		++mp[len][tmp];
		l[++k]=len;
	}
	sort(l+1,l+k+1);k=unique(l+1,l+k+1)-l-1;
	p[0]=1;
	for(int i=1;i<=l[k];++i)p[i]=p[i-1]*base;
	while(m--){
		cin>>(t[0]+1)>>(t[1]+1);
		int len=strlen(t[0]+1);
		for(int j=0;j<2;++j)
			for(int i=1;i<=len;++i)
				hsh[j][i]=hsh[j][i-1]*base+t[j][i];
		for(mn=1;t[0][mn]==t[1][mn];++mn);
		for(mx=len;t[0][mx]==t[1][mx];--mx);
		ans=0;
		for(int cur=1;cur<=k;++cur){
			if(l[cur]<mx-mn+1||l[cur]>len)continue;
			int st=max(1,mn-(l[cur]-(mx-mn+1)));
			int ed=min(len,mx+(l[cur]-(mx-mn+1)));
			for(int i=st;i+l[cur]-1<=ed;++i){
				tmp=Hash(0,i,i+l[cur]-1)*p[l[cur]]+Hash(1,i,i+l[cur]-1);
				ans+=mp[l[cur]][tmp];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
