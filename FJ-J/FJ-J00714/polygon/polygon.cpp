#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int dfs(int m,int p,int q){
	if(m>2*a[q+p-1]){
		ans++;
		ans%=998244353; 
	}else{
		m=m-a[0]+a[q+p];
		dfs(m,p,q+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		int s1=0;
		for(int j=0;j<i;j++){
			s1+=a[i];
		}
		dfs(s1,i,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
