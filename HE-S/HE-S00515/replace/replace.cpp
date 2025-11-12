#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=m;i++){
		long long an=0;
		string aska,askb;
		cin>>aska>>askb;
		if(aska.size()==askb.size()){
			for(int j=0;j<aska.size();j++){
				string ra=aska.substr(0,j);
				string rb=askb.substr(0,j);
				if(ra==rb){
					string sa="",sb="";
					for(int k=j;k<aska.size();k++){
						sa=sa+aska[k];
						sb=sb+askb[k];
						string ta=aska.substr(k+1);
						string tb=askb.substr(k+1);
						if(ta==tb&&mp[sa]==sb){
							an++;
						}
					}			
				}
			}			
		}
		cout<<an<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
