#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	map<string,map<string,long long> >mp;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1][s2]++;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		long long ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int j=0,len=s1.size();
		for(int lon=1;lon<=len;lon++){
			for(int j=0;j<=len-lon;j++){
				if(s1.substr(0,j)==s2.substr(0,j)&&s1.substr(j+lon,len-j-lon)==s2.substr(j+lon,len-j-lon))ans+=mp[s1.substr(j,lon)][s2.substr(j,lon)];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//期望得分 10 O(q*L2^2) 
