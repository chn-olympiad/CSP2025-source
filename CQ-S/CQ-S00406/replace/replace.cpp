#include<bits/stdc++.h>
using namespace std;

namespace cl{
	int n,m;
	string s1[200010],s2[200010];
	void sl(){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			return ;
		}
		int len=a.size();
		int sum=0;
		for(int i=1;i<=n;i++){
			int ll=s1[i].size();
			for(int j=0;j<len;j++){
				bool book=1;
				if(j+ll-1>=len)break;
				if(j>0&&a[j-1]!=b[j-1])return;
				for(int k=j+ll-1;k<len;k++){
					if(a[k]!=b[k]){
						book=0;
						break;
					}
				}
				if(book==0)continue;
				for(int k=j;k<j+ll-1;k++){
					if(a[k]!=s1[i][k-j]||b[k]!=s2[i][k-j]){
						book=0;
						break;
					}
				}
				if(book==0)continue;
				sum++;
			} 
		}
		cout<<sum<<'\n';
	}
	void solve(){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		for(int i=1;i<=m;i++){
			sl();
		}
	}
	int main(){
		int t=1;
//		cin>>t;
		for(int i=1;i<=t;i++){
			solve();
		}
		return 0;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	return cl::main();
}
//18:17 start
//18:29 end
//I will be away from OI.
//I'm yangmeinaixi on luogu. 
