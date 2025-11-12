#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010101;
const int base=233;
const int mod=998244353;
ll n,q,divv[N],t1[N],t2[N],sum1[N],sum2[N],pos[3],len[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	divv[0]=1;
	for(int i=1;i<=5*1e6;i++)divv[i]=divv[i-1]*base%mod;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		len[i]=s1.size();
		s1=' '+s1,s2=' '+s2;
		for(int j=1;j<=len[i];j++)t1[i]=(t1[i]*base%mod+(ll)(s1[j]-'a'+1))%mod;
		for(int j=1;j<=len[i];j++)t2[i]=(t2[i]*base%mod+(ll)(s2[j]-'a'+1))%mod;
	}
	while(q--){
		ll ans=0;
		string s1,s2;
		cin>>s1>>s2;
		ll len1=s1.size(),len2=s2.size();
		s1=' '+s1,s2=' '+s2;
		sum1[0]=0,sum2[0]=0,pos[1]=len1,pos[2]=0;
		if(len1!=len2){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=len1;i++)sum1[i]=(sum1[i-1]*base%mod+(ll)(s1[i]-'a'+1))%mod;
		for(int i=1;i<=len2;i++)sum2[i]=(sum2[i-1]*base%mod+(ll)(s2[i]-'a'+1))%mod;
		for(int i=1;i<=len1;i++){
			if(s1[i]!=s2[i]){
				pos[1]=i;
				break;
			}
		}
		for(int i=len1;i>=1;i--){
			if(s1[i]!=s2[i]){
				pos[2]=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(len[i]<pos[2]-pos[1]+1)continue;
			for(int j=min(pos[1],len1-len[i]+1);j>=1&&j+len[i]>=pos[2];j--){
				ll l=j,r=j+len[i]-1;
				if((sum1[r]-sum1[l-1]*divv[r-l+1]%mod+mod)%mod==t1[i]){
					if((sum2[r]-sum2[l-1]*divv[r-l+1]%mod+mod)%mod==t2[i]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
