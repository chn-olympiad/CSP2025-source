#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1121;
int n,q,ans;
string s[N][3];
string t[N][3];
void dfs(string a,int x,string b){
	for(int i=x;i<a.size();i++){
		for(int j=1;j<=n;j++){
			if(i+s[j][1].size()-1>=a.size()) continue;
			bool flag=1;
			for(int k=0,t=i;k<s[j][1].size();k++,t++){
				if(s[j][1][k]==a[t]) continue;
				flag=0;
				break;			
			} 
			if(!flag) continue;
			for(int k=0,t=i;k<s[j][2].size();k++,t++) a[t]=s[j][2][k];
			if(a==b) ans++;
			for(int k=0,t=i;k<s[j][2].size();k++,t++) a[t]=s[j][1][k];
		}
	} 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2],ans=0;
		dfs(t[i][1],0,t[i][2]);
		printf("%d\n",ans);
	}
	return 0;
}
