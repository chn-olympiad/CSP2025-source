#include<bits/stdc++.h>
using namespace std;
string sa[200007],sb[200007];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=q;i++){
		string ss,st,mb,h=0;
		cin>>ss>>mb;
		for(int j=1;j<=n;j++){
			st=ss;
			int g=ss.find(sa[j]);
			if(g!=-1){
				for(int k=g;k<g+sa[j].size();k++){
					st[k]=sb[j][k-g];
				}
				if(st==mb){
					h++;
				}
			}
		}
		cout<<h<<endl;
	}
}
