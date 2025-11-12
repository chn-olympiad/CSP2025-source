#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
int n,q;
map < pair <string,string> ,int> mp,mp2;
void solve1(){
	
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(mp2[{s1,s2}]) continue;
		mp2[{s1,s2}]++;
		int len=s1.size();
		int l=0,r=len-1;
		for(int i=0;i<=len-1;i++){
			if(s1[i]==s2[i]&&l<r) l++;
			else break;
		}
		for(int i=len-1;i>=0;i--){
			if(s1[i]==s2[i]&&r>l) r--;
			else break;
		}
		string k1="",k2="";
		for(int i=l;i<=r;i++){
			k1+=s1[i];
			k2+=s2[i];
		}
//		cout<<k1<<" "<<k2<<"\n";
		mp[{k1,k2}]++;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		int l=0,r=len-1;
		for(int i=0;i<=len-1;i++){
			if(s1[i]==s2[i]&&l<r)l++;
			else break;
		}
		for(int i=len-1;i>=0;i--){
			if(s1[i]==s2[i]&&r>l)r--;
			else break;
		}
		string k1="",k2="";
		for(int i=l;i<=r;i++){
			k1+=s1[i];
			k2+=s2[i];
		}
//		cout<<k1<<" "<<k2<<"\n";
		cout<<mp[{k1,k2}]<<"\n";
	}
	

	
	return 0;
} 
