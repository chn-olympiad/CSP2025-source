//GZ-S00135 遵义市新蒲新区滨湖中学 安李晨
#include <bits/stdc++.h>
using namespace std;
int n,m,lu,ta,tm=0;
long long ans;
int t=1;
string s;
int a[510];
int na[20];
int used[510];
void dfs(int d){
	if(d>n){
		if(lu>=m){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			if(a[i]-ta<=0||na[d]==0){
				ta++;
				used[i]=1;
				dfs(d+1);
				used[i]=0;
				ta--;
			}
			else{
				used[i]=1;
				lu++;
				dfs(d+1);
				used[i]=0;
				lu--;
			}
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		na[i]=s[i-1]-'0';
		if(na[i]==0) t=0;
	}
	if(t||m==1){ //特判A
		ans=1;
		for(long long i=n;i>=1;i--){
			ans=((ans % 998244353)*i)%998244353;
		}

	}
	else if(m==n){
		ans=0;
	}
	else{
		dfs(1);
	}
	cout<<ans;

	return 0;
}
