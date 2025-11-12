#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,ans;
string sx[N],sy[N],tsx,tsy;
void dfs(int now,string s){
	
	int len=s.size()-1;
	if(now>=len){
		if(s==tsy){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		int lenx=sx[i].size(),leny=sy[i].size();
		if(len-now>=lenx && s.substr(now,lenx)==sx){
			string sf=s.substr(0,now),se=s.substr(lenx+1,len-lenx-1);
			dfs(now+lenx,sf+sy+se);
			dfs(now+1,s);
		}
		if(len-now>=leny && s.substr(now,leny)==sy){
			string sf=s.substr(0,now-1),se=s.substr(leny+1,len-leny-1);
			dfs(now+leny,sf+sx+se);
			dfs(now+1,s);
		}
	}
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sx[i]>>sy[i];
		
	}
	while(q--){
		ans=0;
		cin>>tsx>>tsy;
		dfs(0,tsx);
	}
}
