#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[505];
int a[505],b[505];
int t[505];
long long ans;
bool check(){
	int shu=0;
	for(int i=1;i<=n;i++){
		if(b[i]<a[t[i]]&&c[i]=='1')
			shu++;
	}
	return shu>=m;
}
void dfs(int step){
	if(step>n){
		if(check())
			ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		bool d=1;
		for(int j=1;j<=step;j++){
			if(t[j]==i){
				d=0;
				break;
			}
		}
		if(d==1){
			t[step]=i;
			dfs(step+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0')
			b[i]=b[i-1]+1;
		else
			b[i]=b[i-1];
	}
//	for(int i=1;i<=n;i++)
//		cout<<b[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans%998244353;
	return 0;
}
