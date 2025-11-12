#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans;
int x[1000010];
bool bo[1000010];  
void dfs(int xx,int cnt,int num,int da){
	if (cnt+num==n-1){
		if (cnt>=x[xx])	cnt++; 
		else if (s[da]=='1')	num++;
		if (num>=m)	ans++;
	}
	if (cnt>=x[xx]||s[da]=='0')	{
		bo[xx]=1;
		for (int i=1;i<=n;i++){
			if (!bo[i]){
				dfs(i,cnt+1,num,da+1);
			}
		}
		bo[xx]=0;
	}
	else if (s[da]=='1'){
		bo[xx]=1;
		for (int i=1;i<=n;i++){
			if (!bo[i]){
				dfs(i,cnt,num+1,da+1);
			}
		}
		bo[xx]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	dfs(1,0,0,1);
	cout<<ans<<endl;
	return 0;
}
