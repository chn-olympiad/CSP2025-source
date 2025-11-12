#include<iostream>
#include<string>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+5; 
string s[N],t[N];
int lef[N],rig[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		int minn=1e18,maxx=-1e18;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]!=t[i][j])minn=min(minn,j),maxx=max(maxx,j);
		}
		lef[i]=minn,rig[i]=maxx;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int minn=1e18,maxx=-1e18;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i])minn=min(minn,i),maxx=max(maxx,i);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(maxx-minn+1!=rig[i]-lef[i]+1)continue;
			bool fl=true;
			for(int j=minn,k=lef[i];j<=maxx;j++,k++){
				if(s[i][k]!=a[j] || t[i][k]!=b[j]){
					fl=false;
					break;
				}
			}
			if(!fl)continue;
			if(minn<lef[i] || a.size()-maxx-1<s[i].size()-rig[i]-1)continue;
			for(int j=lef[i]-1,k=minn-1;j>=0 && k>=0;j--,k--){
				if(s[i][j]!=a[k]){
					fl=false;
					break;
				}
			}
			if(!fl)continue;
			for(int j=rig[i]+1,k=maxx+1;j<s[i].size() && k<a.size();j++,k++){
				if(s[i][j]!=a[k]){
					fl=false;
					break;
				}
			}
			if(fl)cnt++;
		}
		cout<<cnt<<endl;
	}
}
