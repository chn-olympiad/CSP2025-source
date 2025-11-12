#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

 int n,q;
 pair<string ,string>a[N];
 map<int,int>vis;
 string s,b;
 int ans;
 void bfs(string a1,string a2,int i){
 	
			int is=s.find(a1),ib=b.find(a2);
			if(is==-1){
				return; 
			}
			string s1="";
			for(int j=0;j<is;j++){
				s1+=s[j];
			}
			s1+=a2;
			for(int j=is+int(a1.length());j<int(s.length());j++) {
				s1+=s[j];
			}

			ans+=(s1==b&&!vis[i]);
			vis[i]=1;
		
 }
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		
		cin>>s>>b;
		if(int(s.length())!=int(b.length())){
			cout<<0;
			continue;
		}
		vis.clear();
		ans=0;
		for(int i=1;i<=n;i++)
			bfs(a[i].first,a[i].second,i);
		cout<<ans<<endl;
	}

	return 0;
}
