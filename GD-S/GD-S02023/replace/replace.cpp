#include<bits/stdc++.h>
using namespace std;
int n,q,p[200001];
string t1[200001],t2[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			string h=t1[i]+"#"+s1;
			for(int j=t1[i].size()+1,k=0;j<h.size();j++){
				while(k&&h[j]!=h[k])k=p[k];
				if(h[k]==h[j])k++;
				p[j]=k;
				if(p[j]==t1[i].size()){
					string l=s1;
					l.replace(j-2*t1[i].size(),t2[i].size(),t2[i]);
					if(l==s2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
