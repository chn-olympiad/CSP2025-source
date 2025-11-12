#include<bits/stdc++.h>
using namespace std;
const long long g=5005,N=998244353;
long long n,a[g],sum,ans,ug;
bool v[g];
void dfs(long long step,long long x){
	if(step==0){
		ans++;
		ans%=N;
	}
	for(int i=step;i<=x;i++){
		if(ug=0){
			ug=a[i];
			v[i]=1;
			dfs(step-1,i);
			v[i]=0;
		}else{
			if(v[i]==0&&a[i]<ug){
				v[i]=1;
				dfs(step-1,i);
				v[i]=0;
			}	
		}	
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,n);
		ug=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
