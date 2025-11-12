#include<bits/stdc++.h>
using namespace std;
struct ed{
	string s1,s2;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a.s1>>a.s2;
	}
	while(q--){
		sring s3,s4;
		cin>>s3>>s4;
		queue<string> q;
		q.push(s3);
		while(!q.empty){
			string sq=q.front();
			q.pop();
			for(int i=1;i<=n;++i){
				auto d=sq.find(a.s1);
				string sd=sq;
				if(d!=nops::string){
					for(int j=d,u=0;j<d+a.s1.size();++j,++u){
							sd[j]=a.s1[u];
					}
				}
			}
		}
	}
	
	return 0;
}
