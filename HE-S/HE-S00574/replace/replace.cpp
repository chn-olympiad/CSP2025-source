#include<bits/stdc++.h>
using namespace std;
pair<string,string>pa[200005];
int n,q;
map<string,bool>vis;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>pa[i].first>>pa[i].second;
		string sum=pa[i].first+pa[i].second;
		vis[sum]=true;
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int i=0;
		while(t1[i]==t2[i]){
			i++;
		}
		int j=t1.size()-1;
		while(t1[j]==t2[j]){
			j--;
		}
		int cnt=0;
		char c1[5000005],c2[5000005];
		for(int k=i;k<=j;k++,cnt++){
			c1[cnt]=t1[k];
			c2[cnt]=t2[k];
		}
		cout<<c1<<c2;
//		if(vis[c1+c2]==true)ans++;
//		cout<<ans<<'\n';
	}
	return 0;
}
