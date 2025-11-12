#include<bits/stdc++.h>
using namespace std;

int n,q;
string ns[200005][3];
int nex[5000005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ns[i][1]>>ns[i][2];
	}
//	cout<<"aaa";
	for(int t=1;t<=q;t++){
		string a,b;
		int ans=0;
		cin>>a>>b;
		memset(nex,0,sizeof nex);
		for(int x=0,y=1;y<a.size();y++){
			if(a[x]==a[y]){
				nex[y+1]=++x;
				continue;
			}
			while(a[x]!=a[y] && x>0){
				x=nex[x];
			}
		}
//		cout<<"bbb";
		for(int i=1;i<=n;i++){
			int f=0;
			for(int x=0,y=0;y<a.size();y++){
				if(ns[i][1][x]==a[y]){
					x++;
				}else{
					x=nex[y+1]-1;
				}
				if(x==ns[i][1].size()-1){
					f=y;
					break;
				}
			}
//			cout<<f<<'\n';
			string tmpa=a;
			for(int j=0;j<ns[i][1].size();j++){
				tmpa[f-ns[i][1].size()+1+j]=ns[i][2][j];
			}
//			for(int y=0;y<a.size();y++){
//				cout<<tmpa[y];
//			}
//			cout<<'\n';
			if(tmpa==b){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0; 
}
