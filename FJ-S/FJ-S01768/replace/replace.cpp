#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200500],b[200500];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++){
		string x,y;
		int s=0;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			if(x.find(a[i])!=-1&&x.size()-a[i].size()+b[i].size()==y.size()) {
				int w=x.find(a[j]);
				string ax,ay,sx;
				for(int k=0;k<w;k++) ax+=x[k];
				int ww=w+ax.size()-1;
				for(int k=ww;k<x.size();k++) ay+=x[k];
				sx=ax+b[i]+ay;
				if(sx==y) s++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}

