#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+7;
const ll jz=31;
ll quick[N],hashs[N],hasht[N];
string fr[N],to[N],s,t;
ll qhs(ll l,ll r){
	return hashs[r]-hashs[l-1]*quick[r-l+1];
}
ll qht(ll l,ll r){
	return hasht[r]-hasht[l-1]*quick[r-l+1];
}
void gh(){
	quick[0]=1;
	hashs[0]=s[0]-'a'+1;
	hasht[0]=t[0]-'a'+1;
	for(ll i=1;i<=s.size()-1;i++){
		hasht[i]=hasht[i-1]*jz+t[i]-'a'+1;
		quick[i]=quick[i-1]*jz;
		hashs[i]=hashs[i-1]*jz+s[i]-'a'+1;
	}
}
void in(string &ls){
	char c=getchar();
	while(c>'z'||c<'a'){
		c=getchar();
	}
	while(c<='z'&&c>='a'){
		ls=ls+c;
		c=getchar();
	}
}
map<ll,map<ll,ll> > m;
ll n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>fr[i]>>to[i];
//		cout<<fr[i]<<' ';
		ll bg=fr[i].size();
//		cout<<bg;
		for(ll j=fr[i].size()-1;j>=0;j--){
			if(fr[i][j]==to[i][j]){
				bg=j;
			}else{
				break;
			}
		}
		
		ll ls=0,ls1=0;
		for(ll j=0;j<=bg-1;j++){
			ls=ls*jz+fr[i][j]-'a'+1;
		}
		for(ll j=0;j<=bg-1;j++){
			ls1=ls1*jz+to[i][j]-'a'+1;
		}
//		cout<<bg<<' '<<ls<<' '<<ls1<<endl;
		m[ls][ls1]++;
	}
	while(q--){
		cin>>s>>t;
		gh();
//		cout<<s<<t
		ll ans=0;
		bool flag=0;
		for(ll i=0;i<s.size()-1;i++){
			if(s[i]!=t[i]){
				if(flag){
					break;
				}else{
					flag=1;
				}
			}
			ll l=i,r=n;
			while(l<r){
				ll mid=(l+r)>>1;
				if(qhs(mid,n)==qht(mid,n)){
					r=mid;
				}else{
					l=mid+1;
				}
			}
			l--;
			map<ll,ll> ls=m[qhs(i,l)];
//			cout<<ls[qht(i,l)]<<' '<<i<<' '<<l<<endl;
			ans+=ls[qht(i,l)];
		}
		cout<<ans<<endl;
	}
	return 0;
}
