#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,q;
string s1[1010],s2[1010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=-1,r=(int)s1.length();
		while(l+1<s1.length() and s1[l+1]==s2[l+1]){
			l++;
		}
		while(r-1>=0 and s1[r-1]==s2[r-1]){
			r--;
		}
		l++;
		r--;
		string s="";
		for(int i=l;i<=r;i++){
			s+=s1[i];
			s+=s2[i];
		}
		if(l<=r)mp[s]++;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[0]>>s2[0];
		if(s1[0].length()!=s2[0].length()){
			cout<<0;
			continue;
		}
		int l=-1,r=(int)s1[0].length();
		while(l+1<s1[0].length() and s1[0][l+1]==s2[0][l+1]){
			l++;
		}
		while(r-1>=0 and s1[0][r-1]==s2[0][r-1]){
			r--;
		}
		l++;
		r--;
		string s="";
		for(int i=l;i<=r;i++){
			s+=s1[0][i];
			s+=s2[0][i];
		}
		cout<<mp[s]<<endl;
	}
	return 0;
}

