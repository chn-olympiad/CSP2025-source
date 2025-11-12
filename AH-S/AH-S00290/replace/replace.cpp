#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;
	cin>>n>>Q;
	map<string,string>mp;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(Q--){
		map<string,int>mp1;
		string t1,t2;
		cin>>t1>>t2;
		queue<string>q;
		int ans=0;
		q.push(t1);
		while(!q.empty()){
			string s=q.front();
			q.pop();
			int len=s.size();
			for(int i=0;i<len;i++){
				for(int j=0;i+j<=len;j++){
					if(mp[s.substr(i,j)]!=""){
						string tmp;
						tmp=s.substr(0,i)+mp[s.substr(i,j)]+s.substr(i+j,len-i-j);
						if(!mp1[tmp]){
							if(tmp==t2){
								ans++;
								continue;
							}
							q.push(tmp);
							mp1[tmp]=1;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
