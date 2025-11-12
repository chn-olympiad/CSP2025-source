#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b,s,s1;
map<pair<string, string> ,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	if(n>100000){
		for(int i=1;i<=n;i++){
			s="",s1="";
			cin>>a>>b;
			if(a==b)continue;
			int l=0,r=a.size();
			while(a[l]==b[l])l++;
			while(a[r]==b[r])r--;
			s="",s1="";
			for(int j=l;j<=r;j++){
				s+=a[j];
				s1+=b[j];
			}
			mp[make_pair(s,s1)]++;
		}
		while(q--){
			cin>>a>>b;
			if(a.size()!=b.size()){
				cout<<0<<endl;
				continue;
			}
			int l=0,r=a.size()-1;
			while(a[l]==b[l])l++;
			while(a[r]==b[r])r--;
			s="",s1="";
			for(int i=l;i<=r;i++){
				s+=a[i];
				s1+=b[i];
			}
			cout<<mp[make_pair(s,s1)]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		s="",s1="";
		cin>>a>>b;
		if(a==b)continue;
		mp[make_pair(a,b)]++;
	}
	while(q--){
		int ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=a.size()-1;
		while(a[l]==b[l])l++;
		while(a[r]==b[r])r--;
		s="",s1="";
		int le=a.size()-1;
		for(int i=max(0,l-250);i<=l;i++){
			s="",s1="";
			for(int j=i;j<r;j++){
				s+=a[j];
				s1+=b[j];
			}
			for(int j=r;j<=min(le,r+250);j++){
				s+=a[j];
				s1+=b[j];
				ans+=mp[make_pair(s,s1)];
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
