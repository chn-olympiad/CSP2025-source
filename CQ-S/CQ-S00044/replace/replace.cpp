#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string>>p;
void solve(){
	cin>>n>>q;
	p.resize(n+5);
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int l=s1.size();
		int sum=0;
		for(int i=1;i<=n;i++){
			int l2=p[i].first.size();
			for(int j=0;j+l2<=l;j++){
				string t=s1;
				string a=p[i].first;
				string b=p[i].second;
				bool flag=true;
				for(int k=0;k<l2;k++){
					if(!(s1[k+j]==a[k])){
						flag=false;
						break;
					}
				}
				if(flag){
					for(int k=0;k<l2;k++){
						t[k+j]=b[k];
					}
				}
				if(t==s2){
					sum++;
				}
			}
			
		}
		cout<<sum<<endl;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}

