#include<bits/stdc++.h>
using namespace std;
bool s[606];
int c[606];
bool used[606];
int ans=0;
void dfs(int now,int cc,int all,int n_pas,int m){
	if(now==all){
		if(n_pas>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	int ccc;
	int pas;
	bool have=0;
	for(int i=0;i<all;i++){
		if(!used[i]){
			have=1;
			used[i]=1;
			pas=n_pas;
			if(!s[now] or cc>=c[i]){
				//cout<<i<<" 0"<<endl;
				ccc=cc+1;
			}
			else{
				//cout<<i<<" 1"<<endl;
				pas=n_pas+1;
				ccc=0;
			}
			dfs(now+1,ccc,all,pas,m);
			used[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool A=1;
	string a;
	cin>>a;
	for(int i=0;i<n;i++){
		s[i]=(a[i]=='1');
		if(s[i]==0){
			A=0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(A){
		int sss=1;
		for(int i=1;i<=n;i++){
			sss*=i;
			sss%=998244353;
		}
		cout<<sss;
	}
	else{
		dfs(0,0,n,0,m);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
