#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1[200005],s2[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i =1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i = 1;i<=n;i++){
			for(int l =0;l+s1[i].size()<=t1.size();l++){
				int f=1;
				for(int r=0;r<s1[i].size();r++){
					if(t1[l+r]!=s1[i][r]){
						f=0;break;
					}
				}
				if(f){
					for(int r=0;r<s1[i].size();r++){
						t1[l+r]=s2[i][r];
					}
					//cout<<t1;
					break;
				}
			}
			int fl=1;
			for(int i =0;i<t1.size();i++){
				if(t1[i]!=t2[i]){
					fl=0;break;
				}
			}
			if(fl)ans++;
		}
		cout<<0<<'\n';
	}
	return 0;
}


