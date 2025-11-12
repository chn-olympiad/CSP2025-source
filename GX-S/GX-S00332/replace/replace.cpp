#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
unordered_map<int,int>mp,da;
int n,q,base=619,len,df,ans,fd,ba[10000006];
long long hx[5000005];
string s1,s2;
struct ss{
	string s1,s2;
}t[200005];
bool cmp(ss x,ss y){
	return x.s1.size()<y.s1.size();
}
int hhx(int l,int r){
	return (hx[r]-hx[l-1]*ba[2*(r-l+1)]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	ba[0]=1;
	for(int i=1;i<=10000000;i++)ba[i]=(1ll*ba[i-1]*base)%mod;
	for(int i=1;i<=n;i++)cin>>t[i].s1>>t[i].s2;
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++){
		s1=t[i].s1,s2=t[i].s2;
		len=s1.size();
		s1="1"+s1;
		s2="1"+s2;
		df=0;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j])df=j;
			hx[j]=(hx[j-1]*base%mod+s1[j])%mod;
			hx[j]=(hx[j]*base%mod+s2[j])%mod;
		}
		int l=1,r=s1.size()-1,res=0,mid=(l+r)>>1;
		while(l<=r){
			if(mp[hhx(1,mid)])l=mid+1,res=mid;
			else r=mid-1;
			mid=(l+r)>>1;
		}
		if(res&&df<=res)da[hhx(1,len)]=da[hhx(1,res)]+1;
		else da[hhx(1,len)]=1;
		for(int j=1;j<=len;j++)mp[hhx(1,j)]=1;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		len=s1.size();
		s1="1"+s1;
		s2="1"+s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		df=0;
		fd=len;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j])fd=min(fd,j);
			if(s1[j]!=s2[j])df=j;
			hx[j]=(hx[j-1]*base%mod+s1[j])%mod;
			hx[j]=(hx[j]*base%mod+s2[j])%mod;
		}
		ans=0;
		for(int j=1;j<=fd;j++){
			int l=j,r=len,res=0,mid=(l+r)>>1;
			while(l<=r){
				if(mp[hhx(j,mid)])l=mid+1,res=mid;
				else r=mid-1;
				mid=(l+r)>>1;
			}
			if(res&&res>=df)ans+=da[hhx(j,res)];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
8 2
xabcx xadex
xabcx xadex
xabcx xadex
xabcx xadex
xabcx xadex
xabcxx xadexx
xabc xade
abcx adex
xabcxx xadexx
xabcx xadex
*/
