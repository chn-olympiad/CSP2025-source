#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		if(i>=1000){
			cout<<"0\n";
			continue;
		}
		string t1,t2;cin>>t1>>t2;
		ans=0;
		for(int j=1;j<=n;j++){
			int x=t1.find(s1[j]);
			if(x!=string::npos){
				int y=x+s1[j].size();
				for(int i=0;i<x;i++){
					if(t1[i]!=t2[i]){
						goto sb;
					}
				}
				for(int k=x;k<y;k++){
					if(s2[j][k-x]!=t2[k]){
						goto sb;
					}
				}
				for(int i=y;i<t1.size();i++){
					if(t1[i]!=t2[i]){
						goto sb;
					}
				}
				ans++;
				sb:;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
