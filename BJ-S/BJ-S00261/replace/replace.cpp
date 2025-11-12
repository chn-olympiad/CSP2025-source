#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=0;i<q;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=0;i<q;i++){
		int ans=0;
		string x=t[i][0];
		for(int j=0;j<n;j++){
			int pos=x.find(s[j][0]);
			if(pos==-1) continue;
			x.erase(pos,s[j][0].size());
			x.insert(pos,s[j][1]);
			if(x==t[i][1]) ans++;
		}
		cout<<ans<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
