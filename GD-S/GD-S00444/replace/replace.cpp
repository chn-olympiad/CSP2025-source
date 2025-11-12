#include<bits/stdc++.h>
using namespace std;
const int N=5e6+1;
int n,q;
map<string,int>a,b;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		a[x]=i,b[y]=i;
	}
	while(q--){
		int l=-1,r,ans=0;
		bool vis=1;
		string x,y,res,res2;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				r=i;
				if(l==-1)l=i;
			}
		}
//		cout<<l<<' '<<r<<'\n';
		for(int i=0;i<=l;i++){
			for(int j=r;j<x.size();j++){
				string t1,t2;
				for(int k=i;k<=j;k++)
					t1+=x[k],t2+=y[k];
//				cout<<t1<<' '<<t2<<'\n';
				if(a.find(t1)!=a.end()&&b.find(t2)!=b.end()){
					if(a[t1]==b[t2])ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
