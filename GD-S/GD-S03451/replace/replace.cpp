#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
typedef long long ll;
typedef pair<int,int> pii;
int num;
int n,q;
//vector<int>e[N];
unordered_map<string,int>mp;
bool f[1050][1050];
int idx;
void cal(string s1,string s2){
	if(s1.size()!=s2.size()){
		cout<<0<<"\n";
		return;
	}
	int ans = 0;
	int l=0,r=0;
	for(int i = 0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			if(!l)l=r=i;
			else r=i; 
		}
	}
	for(int i = 0;i<=l;i++){
		string ss1="",ss2="";
		for(int j =i;j<=r;j++)ss1+=s1[j],ss2+=s2[j];
		if(mp[ss1]&&mp[ss2]&&f[mp[ss1]][mp[ss2]])ans++;
	}
	if(r!=(int)s1.size()-1){
		if(mp[s1]&&mp[s2]&&f[mp[s1]][mp[s2]])ans++;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i = 1;i <= n; i++){
		string s1,s2;
		cin>>s1>>s2;
		if(!mp[s1])mp[s1] = ++idx;
		if(!mp[s2])mp[s2] = ++idx;
		f[mp[s1]][mp[s2]]=1;
	}
	for(int i = 1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		cal(s1,s2);
	}
	return 0;
}  
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
