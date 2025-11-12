#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1005][2];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1,m,ans;i<=q;i++){
		string t0,t1;
		cin>>t0>>t1,m=t0.size(),ans=0;
		if(t0.size()!=t1.size()){
			cout<<"0\n";
			continue;
		}
		for(int j=1,mm;j<=n;j++){
			mm=s[j][0].size();
			if(m<mm)
				continue;
			string t00="",t01=t0.substr(0,mm),t02=t0.substr(mm);
			string t10="",t11=t1.substr(0,mm),t12=t1.substr(mm);
			for(int k=1;;k++){
				if(t00==t10&&t01==s[j][0]&&t11==s[j][1]&&t02==t12)
					ans++;
				if(t02.empty())
					break;
				t00+=t01.front(),t01=t0.substr(k,mm),t02=t0.substr(k+mm),
				t10+=t11.front(),t11=t1.substr(k,mm),t12=t1.substr(k+mm);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}