#include<bits/stdc++.h>
using namespace std;

map<string,string> mp,mb;
	
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a]=b;

		//cout<<a<<" "<<b<<endl;
	}
	for(int i=1;i<=q;i++){

		cin>>a;
		cin>>b;

		int l,r;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				l=j;
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				r=j;
				break;
			}
		}
		int ans=0;
		for(int p=0;p<=l;p++){
			
			string s,y;
			for(int u=p;u<r;u++){
				s+=a[u],y+=b[u];
			}
			for(int k=r;k<a.size();k++){
				s+=a[k];
				y+=b[k];
	
				if(mp[s]==y){
					ans++;
				}
				
			}
		}
		cout<<ans<<"\n";
		
	}
	
	
	
	return 0;
}