#include<bits/stdc++.h>
using namespace std;
string s[200005][3];
int n,q;
string a,b; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>a>>b;
		int l=-1,r=a.size()-1;
		for(int i=0;i<a.size();++i){
			if(l==-1&&a[i]!=b[i]){
				l=i;
			}
			if(l!=-1&&a[i]==b[i]){
				r=i-1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int k=s[i][1].size()-1;
			int x=a.find(s[i][1]);
			int y=b.find(s[i][2]);
			if(x<0||y<0)continue;
			if(x<=l&&x+k>=r&&y<=l&&y+k>=r)ans++;
//			cout<<ans<<endl;
//			cout<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
		}
		cout<<ans<<endl;
	}
}

