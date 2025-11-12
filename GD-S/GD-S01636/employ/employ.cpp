#include<bits/stdc++.h>
using namespace std;
int a,s,g[10010];
string d;
int f[10010],ans;
bool st[10010];
void dfs(int step){
	if(step>=a){
		int sum=0;
		for(int i=0;i<a;i++){
			if(sum>=g[f[i]]||d[i]=='0'){
				sum++;
			}
		}
		if(a-sum>=s)ans++;
		return;
	}
	for(int i=1;i<=a;i++){
		if(!st[i]){
			st[i]=1;
			f[step]=i;
			dfs(step+1);
			st[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>s>>d;
	for(int i=1;i<=a;i++){
		scanf("%d",&g[i]);
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
} 
