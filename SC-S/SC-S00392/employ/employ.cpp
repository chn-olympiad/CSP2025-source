#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],cnt,ans;
bool dis[505];
string s;
int qc(int x){
	int fq=0;
	for(int i;i<=n;i++){
		if(c[i]>=x)fq++;
	}
	return fq;
}
void dfs(int day,int fq){
	if(cnt==m){
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==true)continue;
		if(c[i]>=fq)continue;
		if(s[day-1]=='1')cnt++;
		else fq++;
		dis[i]=true;
		dfs(day+1,qc(fq));
		if(s[day-1]=='1')cnt--;
		else fq--;
		dis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}