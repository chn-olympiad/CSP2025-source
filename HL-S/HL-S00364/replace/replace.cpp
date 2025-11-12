#include<iostream>
#include<map>
using namespace std;
const int MAXN=2E5+10;
string s1,s2;
map<pair<string,string>,int>mp;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[{s1,s2}]++;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
		}
		int l=0,r=t1.size()-1;
		while(t1[l]==t2[l]){
			l++;
		}
		while(t1[r]==t2[r]){
			r--;
		}
		long long ans=0;
		for(int i=0;i<=l;i++){
			for(int j=r,len=t1.size();j<len;j++){
				ans+=mp[{t1.substr(i,j-i+1),t2.substr(i,j-i+1)}];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}