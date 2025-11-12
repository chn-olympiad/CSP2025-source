#include<bits/stdc++.h>
using namespace std;
int N,Q,ans;
bool st[200010];
string s1[200010],s2[200010];
void dfs(string t1,string t2){
	if(t1==t2){
		ans++;
		return;
	}
	int len=t1.size();
	for(int i=1;i<=N;i++){
		int len1=s1[i].size();
		for(int j=0;j+len1-1<len;j++){
			bool flag=true;
			for(int d=j;d<=len1;d++)
				if(st[d]) flag=false;
			if(!flag) continue;
			if(s1[i]==t1.substr(j,len1)){
				string t=t1.substr(0,j-0)+s2[i]+t1.substr(j+len1,len-j-len1);
				for(int d=j;d<=len;d++)
					st[d]=true;
				dfs(t,t2);
				for(int d=j;d<=len;d++)
					st[d]=false;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++)
		cin>>s1[i]>>s2[i];
	while(Q--){
		memset(st,false,sizeof(st));
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		dfs(t1,t2);
		printf("%d\n",ans);
	}
	return 0;
}
