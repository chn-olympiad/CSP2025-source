#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
string s1,s2;
int n,q;
struct node{
	string first,second;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	vector<node> strs(n);
	for(int i=1;i<=n;i++){
		string sa,sb;
		cin>>sa>>sb;
		strs.push_back({sa,sb});
	}
	while(q--){
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		string sin[N]={};
		string si=" ";
		int x=1;
		for(int i=1;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				si+=s1[i];
			}
			if(s1[i]==s2[i] && si!=" "){
				sin[x++]=si;
				si=" ";
			}
		}
		int ans=0;
		for(int i=1;i<=x;i++){
			string si=" ";
			for(int j=1;j<sin[i].size();j++){
				si+=sin[i][j];
				for(int k=1;k<=n;k++){
					if(si==strs[k].first){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
