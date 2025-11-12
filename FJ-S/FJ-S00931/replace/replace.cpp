#include <bits/stdc++.h>
using namespace std;

string s[200001][3];
int c[200001];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int j=0;
		for(;s[i][1][j]!='b';j++);
		int k=0;
		for(;s[i][2][k]!='b';k++);
		c[i]=j-k;
		clog<<c[i]<<endl;
	}
	while(q--){
		string a,b;
		int ans=0;
		cin>>a>>b;
		if(a.size()==b.size()){
			int j=0;
			for(;a[j]!='b';j++);
			int k=0;
			for(;b[k]!='b';k++);
			int x=j-k;
			clog<<x<<endl;
			for(int i=1;i<=n;i++)
				if(c[i]==x)
					ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
