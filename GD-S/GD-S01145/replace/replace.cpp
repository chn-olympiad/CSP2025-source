#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;++i){
		string x,y;
		cin>>x>>y;
		int sum=0;
		for(int i=1;i<=n;++i){
			int u=x.find(s1[i]),len=s1[i].size();
			string z=x;
			if(u==-1)continue;
			for(int k=u;k<len+u;++k)z[k]=s2[i][k-u];
			if(z==y)sum++;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
