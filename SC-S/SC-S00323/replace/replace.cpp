#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[100005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i][0]>>a[i][1];
	}
	for(++q;--q;){
		int ans=0;
		string x,y;cin>>x>>y;
		for(int i=0;i<x.length();++i){
			for(int j=1;j<=n;++j){
				int f=1;
				if(i+a[j][0].length()>x.length()){
					continue;
				}
				for(int k=0;k<i;++k){
					if(x[k]!=y[k]){
						f=0;break;
					}
				}
				for(int k=0;k<a[j][0].length();++k){
					if(x[i+k]!=a[j][0][k]||y[i+k]!=a[j][1][k]){
						f=0;break;
					}
				}
				for(int k=i+a[j][0].length();k<x.length();++k){
					if(x[k]!=y[k]){
						f=0;break;
					}
				} 
				ans+=f;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
