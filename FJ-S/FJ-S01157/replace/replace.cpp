#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		long long sss=0;
		for(int j=1;j<=n;j++){
			int t=t1.find(s[j][0]);
			while(t!=-1){
				string l=t1.substr(0,t)+s[j][1]+t1.substr(t+s[j][0].size());
				if(l==t2){
					sss++;
				}
				t=t1.find(s[j][0],t+1);
			}
		}
		cout<<sss<<"\n";
	}
	return 0;
}
