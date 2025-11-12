#include<bits/stdc++.h>
using namespace std;
const int q=998244353;
string s;
int n,m,a[505],fq=0,yz=0;
long long ans=0;
bool t[505],used[505];
bool check(){
	for(int i=1;i<=n;i++){
		if(used[i]==0) return 0;
	}
	return 1;
}
void dfs(int day){
	if(check()){
		if(yz>=m)ans+=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			if(fq>=a[i]){
				continue;
			}
			if(t[day]==1){
				used[i]=1;
				yz++;
				dfs(day+1);
				yz--;
				used[i]=0;
			}
			else {
				used[i]=1;
				fq++;
				dfs(day+1);
				fq--;
				used[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1') t[i]=1;	
		if(s[i-1]=='0') t[i]=0;
	}
	for(int i=1;i<=n;i++){
		 scanf("%d",&a[i]);
		 if(a[i]==0) a[i]=1;
	}	
	dfs(1);
	cout<<ans%q;
	return 0;
}
