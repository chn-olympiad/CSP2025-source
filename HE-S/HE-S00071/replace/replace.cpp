#include <bits/stdc++.h>
using namespace std;
int n,q;
long long cnt;
string s[200005][3];
string t[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		if(t[i][1].size() != t[i][2].size()){
			cout<<0<<endl;
			continue;
		}
		bool flag=false;
		for(int j=1;j<=n;j++){
			if(t[i][1]==s[i][1]){
				flag=true;
			}
		}
		if(!flag){
			cout<<0<<endl;
			continue;
		}
		if(t[i][1]==s[i][1] && t[i][2]==s[i][2]) cnt++;
		for(int len=1;len<=t[i][1].size();len++){
			string x=t[i][1];
			string y;
			string z;
			for(int j=1;j<=len;j++){
				y=y+x[j];
				if(y==s[i][2]){
					z=s[i][2];
				}
				x=z;
				if(x==t[i][2]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
