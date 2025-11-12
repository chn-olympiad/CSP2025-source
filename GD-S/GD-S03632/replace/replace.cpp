#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5;

struct turn{
	string s,t;
};

turn a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
	#endif
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	for(int x=1;x<=q;x++){
		string s,t;
		cin>>s>>t;
		int len=s.size(),ans=0;
		for(int i=1;i<=n;i++){
			int sz=a[i].s.size();
			for(int j=0;j+sz-1<len;j++){
				string cmp=s.substr(j,sz),to=s.substr(0,j)+a[i].t;
				if(j+sz<len){
					to+=s.substr(j+sz,len-j-sz);
				}
				if(cmp==a[i].s&&to==t){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

