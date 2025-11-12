#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n,q;
ull base=137,h1[200005],h2[200005],sum1[5000005],sum2[5000005];
ull H(string &s){
	int l=s.size();
	ull ans=0;
	for(int i=0;i<l;i++){
		ans=ans*10+s[i];
	}
	return ans;
}
map<pair<ull,ull>,int> mp;
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			i--,n--;
			continue;
		}
		mp[make_pair(H(s1),H(s2))]++;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		for(int i=0;i<l1;i++){
			sum1[i+1]=sum1[i]*10+s1[i];
		}
		for(int i=0;i<l2;i++){
			sum2[i+1]=sum2[i]*10+s2[i];
		}
		ull sum=0,pre=0;
		int bj=0;
		for(int i=1;i<=l1;i++){
			if(s1[i-1]!=s2[i-1]){
				if(bj){
					bj=2;
					break;
				}
				else {
					sum=sum*10+s1[i-1];
					pre=pre*10+s2[i-1];
				}
			}
			else {
				if(!bj){
					bj=1;
					mp[make_pair(sum,pre)];
				}
			}
		}
		if(bj==2){
			cout<<0<<"\n";
		}
	}
	return 0;
}