#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod1=998244353;
const int mod2=1e9+7;
const int mod3=1e9+97;
const int mod4=1e9+33;
const int base1=131;
const int base2=29;
const int base3=37;
const int base4=133;
string s1,s2;
map<pair<pair<pair<int,int>,pair<int,int> >,pair<pair<int,int>,pair<int,int> > >,int> vis;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.length();
		s1=' '+s1;
		s2=' '+s2;
		int lf=1,rt=len;
		while(s1[lf]==s2[lf]&&lf<n) lf++;
		while(s1[rt]==s2[rt]&&rt>=lf) rt--;
		if(rt<lf) continue;
		int sum1=0,sum2=0;
		int suma=0,sumb=0;
		int sumc=0,sumd=0;
		int sume=0,sumh=0;
		for(int j=lf;j<=rt;j++){
			sum1=(sum1*base1%mod1+s1[j]-'a'+1)%mod1;
			sum2=(sum2*base1%mod1+s2[j]-'a'+1)%mod1;
			suma=(suma*base2%mod2+s1[j]-'a'+1)%mod2;
			sumb=(sumb*base2%mod2+s2[j]-'a'+1)%mod2;
			sumc=(sumc*base3%mod3+s1[j]-'a'+1)%mod3;
			sumd=(sumd*base3%mod3+s2[j]-'a'+1)%mod3;
			sume=(sume*base4%mod4+s1[j]-'a'+1)%mod4;
			sumh=(sumh*base4%mod4+s2[j]-'a'+1)%mod4;
		}
		auto point=make_pair(make_pair(make_pair(sum1,sum2),make_pair(suma,sumb)),make_pair(make_pair(sumc,sumd),make_pair(sume,sumh)));
		vis[point]++;
	}
	while(q--){
		cin>>s1>>s2;
		int len1=s1.length(),len2=s2.length();
		if(len1!=len2){
			cout<<0<<"\n";
			continue;
		}
		s1=' '+s1;
		s2=' '+s2;
		int lf=1,rt=len1;
		while(s1[lf]==s2[lf]&&lf<n) lf++;
		while(s1[rt]==s2[rt]&&rt>lf) rt--;
		int sum1=0,sum2=0;
		int suma=0,sumb=0;
		int sumc=0,sumd=0;
		int sume=0,sumh=0;
		for(int j=lf;j<=rt;j++){
			sum1=(sum1*base1%mod1+s1[j]-'a'+1)%mod1;
			sum2=(sum2*base1%mod1+s2[j]-'a'+1)%mod1;
			suma=(suma*base2%mod2+s1[j]-'a'+1)%mod2;
			sumb=(sumb*base2%mod2+s2[j]-'a'+1)%mod2;
			sumc=(sumc*base3%mod3+s1[j]-'a'+1)%mod3;
			sumd=(sumd*base3%mod3+s2[j]-'a'+1)%mod3;
			sume=(sume*base4%mod4+s1[j]-'a'+1)%mod4;
			sumh=(sumh*base4%mod4+s2[j]-'a'+1)%mod4;
		}
		auto point=make_pair(make_pair(make_pair(sum1,sum2),make_pair(suma,sumb)),make_pair(make_pair(sumc,sumd),make_pair(sume,sumh)));
		cout<<vis[point]<<"\n";
	}
	return 0;
}
