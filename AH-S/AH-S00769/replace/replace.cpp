#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod1 =998244353;
const int mod2 =19260817;
const int cs1=72163321;
int n,q;
string s[200010][2];
int has(string ss){
	int sum=0;
	for(int i=0;i<ss.size();i++){
		sum=(sum*cs1+ss[i]-'a'+1)%mod1;
	}
	return sum;
}
map<int,map<int,int> >mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		mp[has(s[i][0])][has(s[i][1])]++;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l1,l2;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){l1=i;break;}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){l2=i;break;}
		}
		int ans=0;
		for(int i=0;i<t1.size()&&i<=l1;i++){
			int cnt1,cnt2;
			cnt1=cnt2=0;
			for(int j=i;j<t1.size();j++){
				cnt1=(cnt1*cs1+t1[j]-'a'+1)%mod1;
				cnt2=(cnt2*cs1+t2[j]-'a'+1)%mod1;
				if(j>=l2&&mp[cnt1][cnt2])ans+=mp[cnt1][cnt2]/*,cout<<i<<' '<<j<<' '<<cnt1<<' '<<cnt2<<'\n'*/;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
