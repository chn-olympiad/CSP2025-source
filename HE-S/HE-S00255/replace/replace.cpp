#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[200001][2],b[200001][2];
long long ans[200001];
bool comp(int x,int y,int l,int r,string s){
	bool f=1;
	for(int i=0,j=l;i<s.length(),j<=r;i++,j++){
		if(b[x][y][j]!=s[i])
			f=0;
	}
	return f;
}
void swaps(int x,int y,int l,int r,string s){
	for(int i=0,j=l;i<s.length(),j<=r;i++,j++)
		b[x][y][j]=s[i];
}
bool comps(string x,string y){
	bool f=1;
	if(x.length()!=y.length())
		f=0;
	for(int i=0;i<x.length();i++){
		if(x[i]!=y[i])
			f=0;
	}
	return f;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;++i)
		cin>>a[i][0]>>a[i][1];
	for(int i=0;i<q;++i)
		cin>>b[i][0]>>b[i][1];
	for(int i=0;i<q;++i){
		if(b[i][0].length()!=b[i][1].length())
			continue;
		else{
			for(int l=0;l<n;++l){
				for(int r=l;r<n;++r){
					for(int j=0;j<n;++j){
						if(comp(i,0,l,r,a[j][0])){
							swaps(i,0,l,r,a[j][1]);
							if(comps(b[i][0],b[i][1]))
								ans[i]++;
							swaps(i,0,l,r,a[j][0]);
						}
					}
				}
			}
		}
	}
	for(int i=0;i<q;++i)
		cout<<ans[i]<<'\n';
	return 0;
}
