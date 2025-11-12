#include<bits/stdc++.h>
using namespace std;
long long n,k,a[5005],use[5005],cnt;
void dfs(int deep,int m,int k){
	if(deep==0){
		int ans=0;
		for(int i=2;i<=k;i++){
			ans+=use[i];
		}
		if(ans>use[1]){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=m+1;i<=n-deep+1;i++){
		use[deep]=a[i];
		dfs(deep-1,i,k);
		use[deep]=0;
	}
	
}
int c(int a,int b){
	long long cn=1;
	for(int i=b-a+1;i<=b;i++){
		cn*=i; 
	}
	for(int i=1;i<=a;i++){
		cn/=i;
	}
	return cn;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flat=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flat=false;
		}
	}
	if(flat==true){
		for(int i=3;i<=n;i++){
			cnt+=c(i,n);
			cnt%=998244353; 
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,0,i);
	}
	cout<<cnt;
	return 0;
}
