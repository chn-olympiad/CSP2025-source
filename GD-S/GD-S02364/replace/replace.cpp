#include<bits/stdc++.h>
using namespace std;
string a[200001],b[200001],x,y;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		long long s=0;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			int f=x.find(a[j]);
		  //cout<<f<<' ';
			if(f==-1) continue;
			if(y==b[j]) s++;
			else if(x.substr(0,f-1)+b[j]+x.substr(f+a[j].size()-1)==y)
				s++;
		}
		cout<<'\n'<<s<<'\n';
	}
}
