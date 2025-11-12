#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int len=x.size(),ans=0;
		for(int i=1;i<=n;i++){
			int sz=s1[i].size();
			for(int j=0;j+sz-1<len;j++){
				bool flag=true;
				string tx=x;
				for(int k=j;k<j+sz;k++){
					if(x[k]!=s1[i][k-j]){
						flag=false;
						break;
					}
					x[k]=s2[i][k-j];
				}
				if(flag&&x==y){
					ans++;
				}
				x=tx;
			}
		}
		cout<<ans;
	}
	return 0;
}
