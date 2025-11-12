#include<bits/stdc++.h> 
using namespace std;
long long n,a[5005],b[5005],ans;
long long p;
bool v[5005];
bool dbx(long long p){
	long long s=0,mx=0;
	for(int i=1;i<=p;i++){
		s+=b[i];
		if(b[i]>mx){
			mx=b[i];
		}
	}
	if(s>2*mx){
		return 1;
	}else{
		return 0;
	}
}
void dfs(long long m,int k){//m是这一轮一组多少个 k是标记i的 
	if(p==m){
		 if(dbx(p)){
//		 	for(int i=1;i<=p;i++){
//		 		cout<<b[i]<<" ";
//			 }
//			 cout<<"\n";
		 	ans++;
		 }
	}
	for(int i=k+1;i<=n;i++){
		if(v[i]==0){
			p++;
			b[p]=a[i];
			v[i]=1;
			dfs(m,i);
			p--;
			v[i]=0;
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
	for(int i=3;i<=n;i++){
		dfs(i,0);
	}
	
	cout<<ans%998244353;
	
	return 0;
}