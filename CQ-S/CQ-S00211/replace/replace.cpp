#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s1[200010];
string s2[200010];
string t1[200010];
string t2[200010];
unordered_map<string,int> um;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		um[s1[i]]=i;
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i];
		cin>>t2[i];
		int l=INT_MAX,r=INT_MIN;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!=t2[i][j]){
				l=min(l,j);
				r=max(r,j);
			}
		}
		int ans=0;
		for(int j=0;j<=l;j++){
			for(int k=r;k<t1[i].size();k++){
				if((um.find(t1[i].substr(j,k-j+1)))!=um.end()){
//					cout<<j<<" "<<k<<"\n";
					int tt2=um[t1[i].substr(j,k-j+1)];
					if(t2[i].substr(j,k-j+1)==s2[tt2]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

