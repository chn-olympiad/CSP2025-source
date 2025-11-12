#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005][2];
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i][0]>>a[i][1];
	while(q--){
		ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			int len=a[i][0].size();
			for(int j=0;j<s1.size()-len+1;j++){
				string s;
				if(s1.substr(j,len)==a[i][0])s=s1.substr(0,j)+a[i][1]+s1.substr(j+len,n-j-len+1);
				if(s==s2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
