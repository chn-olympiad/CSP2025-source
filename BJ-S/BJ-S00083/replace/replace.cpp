#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string>m;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		cin>>s1>>s2;
		for(int j=0;j<=s1.size();j++){
			for(int k=0;k<=s1.size()-j;k++){
				if(s1.substr(0,j)+m[s1.substr(j,k)]+s1.substr(j+k)==s2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
