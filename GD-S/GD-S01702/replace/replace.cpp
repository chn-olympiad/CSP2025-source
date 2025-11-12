#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s,t;
		cin>>s>>t;
		mp[s]=t;
	}
	for(int i=0;i<q;i++){
		int cnt=0;
		string s,t;
		cin>>s>>t;
		int l=s.size();
		for(int j=0;j<l;j++){
			for(int e=1;j+e<=l;e++){
				string u=s.substr(0,j),v=s.substr(j,e),w=s.substr(j+e,n-j-e+1);
				if(mp[v]!=""&&u+mp[v]+w==t){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

