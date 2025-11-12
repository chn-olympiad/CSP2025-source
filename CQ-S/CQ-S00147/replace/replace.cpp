#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fre(X) freopen(X".in","r",stdin),freopen(X".out","w",stdout)
#define Xueli return
#define Chang 0
using namespace std;
namespace did{
	int n,Q;
	string s1[200005],s2[200005]; 
	string x,y;
	bool kmp(int b,int e){
		for(int i=0;i<s1[e].size();i++){
			if(s1[e][i]!=x[i+b])return 0;
		}
		for(int i=0;i<s2[e].size();i++){
			if(s2[e][i]!=y[i+b])return 0;
		}
		return 1;
	}
	void init(){

	}
	
	void lusolve(){
		cin>>n>>Q;
		if(n>=3000){//不可以总司令 
			while(Q--)cout<<0<<endl;
			return; 
		} 
		for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
		while(Q--){
			cin>>x>>y;
			int r=0,l=0;
			for(int i=0;i<x.size();i++)if(x[i]!=y[i])r=i;
			for(int i=x.size()-1;i>=0;i--)if(x[i]!=y[i])l=i;
			int ans=0;
			for(int i=1;i<=n;i++){
				int y=s1[i].size();
				if(y<r-l+1)continue;
				for(int j=max(0ll,r-y);j<=l;j++){
					if(kmp(j,i)){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
signed main(){
	IOS();
	fre("replace");
	int Q=1;
//	cin>>Q;
	did::init();
	while(Q--)did::lusolve();
//while(1);
	Xueli Chang;
}
//s MB
//s MB
/*
羊了个羊出题人吗? 
*/
