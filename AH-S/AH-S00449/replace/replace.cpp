#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		mp[s]=s1;
	}
	for(int i=1;i<=q;i++){
		string s,s1;
		cin>>s>>s1;
		if(s.size()!=s1.size()){
			cout<<0;
			cout<<"\n";
			continue;
		}
		int cnt=0;
		if(mp[s]==s1){
			cnt++;
		}
		int l=1,r=s.size()-1;
		string s2=s;
		while(l<=r){ 
			s=s2;
			string sum="";
			for(int j=l;j<=r;j++){
				sum+=s[j];
			}
			sum=mp[sum];
			int idx=0;
			for(int j=l;j<=r;j++){
				s[j]=sum[idx];
				idx++;
			}
			if(s==s1){
				cnt++;
			}
			int df=l,ds=r;
			if(s2[l]==s1[l]){
				l++;
			}
			if(s2[r]==s1[r]){
				r--;
			}
			if(df==l&&ds==r) break;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
