#include<bits/stdc++.h>
using namespace std;
int n,q,cnt=0;

map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out ","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string l,r;
		cin>>l>>r;
		mp[l]=r;
	}
	while(q--){
		cnt=0;
		string o,p,ok;
		cin>>o>>p;
		int m=o.size();
		int u=p.size();
		for(int i=0;i<m;i++){
			for(int k=1;i+k<=m;k++){
				ok="";
				for(int j=i;j<=i+k-1;j++){
					ok=ok+o[j];
				}
					string od=o;
					string ou=mp[ok];
					for(int j=i;j<=i+k-1;j++){
						od[j]=ou[j-i];
					}
					if(od==p)cnt++;
				
			}
			
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
