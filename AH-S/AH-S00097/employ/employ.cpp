#include<bits/stdc++.h>
using namespace std;
int n,minn,m,na[510],v[510];
string s;
void dfs(int t,int cc){
	if(cc==0){
		minn++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(na[i]<=t)dfs(t+1,cc-1);
			if(na[i]>t)dfs(t+1,cc);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>na[i];
	sort(na+1,na+1+n);
	dfs(1,n-m);
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
