#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][2],t[200001][2];

int main(){	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i = 0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	
	for(int i = 0;i<q;i++){
		int ans = 0;
		for(int j = 0;j<n;j++){
			bool flag = false;
			int be;
			for(int k = 0,sl = 0,tl = k;k<t[i][0].size()-s[j][0].size();k++){
				be = tl;
				while(s[j][0][sl] == t[i][0][tl]&&sl<s[j][0].size()){
					sl++,tl++;
				}
				if(sl == s[j][0].size()){
					flag = true;
					break;
				}
			}
			
			if(flag){
				string te = t[i][0];
				for(int k = 0;k<s[j][0].size();k++){
					te[k+be] = s[j][1][k];
				}
				
				if(t[i][1] == te) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
