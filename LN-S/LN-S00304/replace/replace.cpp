#include<bits/stdc++.h>
#define int long long
using namespace std;
string a[200010][3],b[200010][3];
string b1,b2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		cin>>b1>>b2;
		int ans=0;
		int lenb1=b1.size(),lenb2=b2.size();
		for(int i=1;i<=n;i++){
			//cout<<a[i][1]<<" "<<a[i][2]<<'\n';
			int len1=a[i][1].size(),len2=a[i][2].size();
			if(lenb1-len1+len2!=lenb2) continue;
			for(int j=0;j+len1<=lenb1;j++){
				//cout<<len1<<" "<<b1.substr(j,len1)<<'\n';
				string s2=b1.substr(0,j)+a[i][2]+b1.substr(j+len1,lenb1-len1-j);
				//cout<<s2<<'\n';
				if(b1.substr(j,len1)==a[i][1]){
					if(s2==b2) ans++;
				}
				//cout<<ans<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}