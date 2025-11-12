#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,mod=998244353,P=131;
ll g1[N],g2[N],sz[N],n1[N],n2[N];
string s1[N],s2[N],t1[N],t2[N];
ll pw[N],qpw[N],pre[N],pos[N];
int n,q,l2;
/*namespace lq{
	for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]){
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b'){
					l[i]=j;
					r[i]=s1[i].size()-j;
					num[++tot]=l[i];
					num[++tot]=r[i];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b'){
					l[i]=j;
					r[i]=s1[i].size()-j;
					num[++tot]=l[i];
					num[++tot]=r[i];
				}
			}
		}
	}
};*/
namespace bf{
	ll get(string s){
		ll num=0;
		for(int i=0;i<s.size();i++)num=(num*P%mod+s[i]-'a'+1)%mod;
		return num;
	}
	bool cha(ll s1,ll add,ll sum,int p,int x,ll s2){
		ll num=(s1+add)%mod;
		if((sum-num)%mod!=g1[x]*pw[max((ll)0,p-sz[x]-1)]%mod)return 0;
		return (num+g2[x]*pw[max((ll)0,p-sz[x]-1)]%mod)%mod==s2;
	}
	void main(){
		for(int i=1;i<=n;i++){
			g1[i]=get(s1[i]);
			g2[i]=get(s2[i]);
			sz[i]=s1[i].size();
		}
		for(int i=1;i<=q;i++){
		//cout<<i<<':'<<endl;
			if(t1[i].size()!=t2[i].size()){
				cout<<0<<endl;
				continue;
			}
			int ans=0;int len=t1[i].size();
			n1[i]=get(t1[i]);
			n2[i]=get(t2[i]);
			for(int j=0;j<t1[i].size();j++)pre[j+1]=(pre[j]*P%mod+t1[i][j]-'a'+1)%mod;
			for(int j=t1[i].size()-1;j>=0;j--)pos[j+1]=(pos[j+2]+(t1[i][j]-'a'+1)*pw[len-j-1]%mod)%mod;
			for(int j=1;j<=t1[i].size();j++){
				for(int k=1;k<=n;k++)if(sz[k]<=j && cha(pos[j+1],pre[j-sz[k]]*pw[len+sz[k]-j]%mod,n1[i],j,k,n2[i])){
					//cout<<j<<' '<<k<<endl;
					ans++;
				}
			}
			printf("%lld\n",ans);
			ans=0;
		}
	}
	
}
ll pwq(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
return ans;
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)cin>>t1[i]>>t2[i];
	for(int i=1;i<=q;i++)l2+=t1[i].size()+t2[i].size();
	pw[0]=1;
	for(int i=1;i<=l2;i++)pw[i]=pw[i-1]*P%mod;
	for(int i=0;i<=l2;i++)qpw[i]=pwq(pw[i],mod-2);
	bf::main();
	//else lq::main();
	return 0;
}