#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],v[505],b[505],ans;
string s;
void dfs(long long l){
	if(l>n){
		long long num;
		for(int i=1;i<=n;i++){
			cout<<b[i]<<" ";
			if(b[i]<num||s[i-1]==0){
				num++;
			}
		}
		if(n-num>m){
			ans++;
		}
//		cout<<endl<<ans<<endl;
		
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			a[l]=i;
			v[i]=1;
			dfs(l+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fcl
}
