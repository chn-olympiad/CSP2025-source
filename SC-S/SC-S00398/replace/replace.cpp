#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> >s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s.push_back(make_pair(x,y));
	} 
	while(q--){
		string tx,ty;
		cin>>tx>>ty;
		int ans;
		for(int i=0;i<n;i++){
			string si=s[i].first;
			string p=tx;
			for(int j=0;j<tx.size();j++){
				if(p[j]==si[0]){
					int y=j;
					while(j<=y+si.size()){
						if(p[j]!=si[j-y]){
							p=tx;
							break;
						}
						else p[j]=si[j-y];
						j++;
					}
					
					
				}
				if(p==ty)ans++;
			}
			
		}
		cout<<0<<endl;
	}
}