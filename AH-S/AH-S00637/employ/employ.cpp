#include<bits/stdc++.h>
using namespace std;
long long n,m;
string aa;
bool a[100000];
long long c[100000];
bool sf[100000];
long long num[100000],ans;
bool check(){
	long long sum=0,zong=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			sum++;
		}else{
			if(sum>=c[num[i]]){
				sum++;
			}else{
				zong++;
			}
		}
	}
	if(zong>=m){
		return 1;
	}else{
		return 0;
	}
}
void dfs(long long x){
	if(x>n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!sf[i]){
			sf[i]=1;
			num[x]=i;
			dfs(x+1);
			sf[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>aa;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<aa.size();i++){
		a[i+1]=aa[i]-'0';
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
	
}
