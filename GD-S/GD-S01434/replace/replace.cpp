#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll mod=94883660938571,tg=131;
int n,q;
string a[2],b[2];
int num[2500005],m,st[200005];
ll po[2500005],ha[2500005];
ll tmp;
int l0[200005],ans;
map<ll,int> mp[200005]; 
map<ll,int>::iterator A;
ll hx,hy;
ll mul(ll x,ll y){
	ll s=0;
	for(;x;x>>=16,y=y*65536%mod)s=(s+(x&65535)*y)%mod;
	return s;
}
static ll gt(int l,int r){
	if(!l)return ha[r];
	return (ha[r]-mul(ha[l-1],po[r-l+1])+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	po[0]=1;
	for(int i=1;i<=2500000;++i)po[i]=po[i-1]*tg%mod*tg%mod;
	for(int i=1,x;i<=n;++i){
		cin>>a[0]>>a[1];tmp=0;
		if(!num[a[0].size()])num[a[0].size()]=++m,st[m]=a[0].size();
		x=num[a[0].size()];
		for(int j=0;j<a[0].size();++j)tmp=(tmp*tg+a[0][j])%mod,tmp=(tmp*tg+a[1][j])%mod;
		++mp[x][tmp];
	}
	sort(st+1,st+1+m);
	for(int i=1,l,r,len,qwq=0;i<=q;++i){
		cin>>b[0]>>b[1];len=b[0].size();
		if(b[0].size()!=b[1].size()){
			cout<<"0\n";
			continue;
		}
		ha[0]=b[0][0]*tg+b[1][0];
		for(int j=1;j<len;++j)ha[j]=(ha[j-1]*tg+b[0][j])%mod,ha[j]=(ha[j]*tg+b[1][j])%mod;
		l=0,r=len-1;ans=0;
		while(b[0][l]==b[1][l])++l;
		while(b[0][r]==b[1][r])--r;
		for(int j=1;j<=m;++j){
			if(st[j]>len)break;
			if(st[j]<r-l+1)continue;
			for(int x=max(0,r-st[j]+1);x<=l&&x+st[j]-1<len;++x){
				tmp=gt(x,x+st[j]-1);
				A=mp[num[st[j]]].find(tmp);
				if(A!=mp[num[st[j]]].end())ans+=(*A).second;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
s1s2串长相同吗有点意思
定义非前后缀匹配为去掉前后缀匹配的部分 
那么s1s2非前后缀匹配要和t1t2非前后缀匹配相同
s1剩下的前缀为t1剩下的前缀的后缀
s1剩下的后缀为t1剩下的后缀的前缀
考虑到不同的长度只有根号种，于是可以枚举长度哈希解决
上限为qsqrt(n)
直接将x也哈希进去 
*/
