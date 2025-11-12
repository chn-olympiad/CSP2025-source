#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3];
string t[3];
int st_s[N],ed_s[N];
int c[5000005];
vector<int> g[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		st_s[i]=-1;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]!=s[i][2][j])
				if(st_s[i]<0){
					st_s[i]=j;ed_s[i]=j;
				}
				else ed_s[i]=j;
		}
		c[ed_s[i]-st_s[i]+1]++;
		g[ed_s[i]-st_s[i]+1].push_back(i);
	}
	while(q--){
		cin>>t[1]>>t[2];
		int st=-1,ed;
		int ans=0;
		if(t[1].size()!=t[2].size()){
			printf("0\n");
			continue;
		}
		for(int i=0;i<t[1].size();i++){
			if(t[1][i]!=t[2][i]){
				if(st<0){
					st=i;ed=i;
				}
				else ed=i;
			}
		}
		for(int i=0;i<g[ed-st+1].size();i++){
			if(s[g[ed-st+1][i]][1].size()>t[1].size()) continue;
			int y=t[1].find(s[g[ed-st+1][i]][1][0]);
			if(y<0) continue;
			bool flag=1;
			for(int j=0;j<s[g[ed-st+1][i]][1].size();j++){
				if(s[g[ed-st+1][i]][1][j]!=t[1][j+y]){
					flag=0;
					break;
				}
			}
			if(!flag) continue;
			y=t[2].find(s[g[ed-st+1][i]][2][0]);
			if(y<0) continue;
			for(int j=0;j<s[g[ed-st+1][i]][2].size();j++){
				if(s[g[ed-st+1][i]][2][j]!=t[2][j+y]){
					flag=0;
					break;
				}
			}
			if(flag) ans++;
		}
		printf("%d\n",ans); 
	}
	return 0;
}
