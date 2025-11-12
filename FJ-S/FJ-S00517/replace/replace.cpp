#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5,mod=998244353;
int n,q,s[maxn],ss[maxn],sss[maxn];
string s1,s2,t1,t2;
map<int,int>mp,mp2; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int l=-1,r=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]&&l==-1) l=j; 
			if(s1[j]!=s2[j]) r=j;
		}
		for(int j=l;j<=r;j++){
			s[i]*=27,s[i]%=mod,s[i]+=s1[j]-'a'+1;
			s[i]*=27,s[i]%=mod,s[i]+=s2[j]-'a'+1;
			s[i]%=mod;
		}
		for(int j=l-1;j>=0;j--){
			ss[i]*=27,ss[i]%=mod,ss[i]+=s1[j]-'a'+1;
			ss[i]*=27,ss[i]%=mod,ss[i]+=s2[j]-'a'+1;
			ss[i]%=mod;
		}
		for(int j=r+1;j<s1.size();j++){
			sss[i]*=27,sss[i]%=mod,sss[i]+=s1[j]-'a'+1;
			sss[i]*=27,sss[i]%=mod,sss[i]+=s2[j]-'a'+1;
			sss[i]%=mod;
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int l=-1,r=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]&&l==-1) l=j; 
			if(t1[j]!=t2[j]) r=j;
		}
		int sum=0,sum2=0,sum3=0;
		for(int j=l;j<=r;j++){
			sum*=27,sum%=mod,sum+=t1[j]-'a'+1;
			sum*=27,sum%=mod,sum+=t2[j]-'a'+1;
			sum%=mod;
		}
		mp.clear(),mp2.clear();
		mp[0]=1,mp2[0]=1;
		for(int j=l-1;j>=0;j--){
			sum2*=27,sum2%=mod,sum2+=t1[j]-'a'+1;
			sum2*=27,sum2%=mod,sum2+=t2[j]-'a'+1;
			sum2%=mod;
			mp[sum2]=1;
		}
		for(int j=r+1;j<t1.size();j++){
			sum3*=27,sum3%=mod,sum3+=t1[j]-'a'+1;
			sum3*=27,sum3%=mod,sum3+=t2[j]-'a'+1;
			sum3%=mod;
			mp2[sum3]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]==sum&&mp[ss[i]]&&mp2[sss[i]]) ans++;
		printf("%lld\n",ans);
	}
}

