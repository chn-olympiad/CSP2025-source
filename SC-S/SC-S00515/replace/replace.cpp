#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
int n,q,ans;
string a[N],b[N],t,t2;
bool c(string s,string y){
	int i=0,j=0;
	while(i<s.size()){
		if(s[i]!=y[j]) return false;
		i++;
		j++;
	}
	return true;
}
void check(int l){
	string s=t;
	for(int i=1;i<=n;i++){
		int f=0;
		if(l+a[i].size()-1>t.size()) continue;
		int j=0,k=l;
		while(j<a[i].size()){
			if(t[k]!=a[i][j]){
				f++;
			}
			k++;
			j++; 
		}
		if(f==0){
			int r=l;
			for(int j=0;j<b[i].size();j++){
				s[r]=b[i][j];
				r++;
			}
			if(c(s,t2)){
				ans++;
			}
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>t>>t2;
		if(t.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<t.size();i++){
			check(i);
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
} 