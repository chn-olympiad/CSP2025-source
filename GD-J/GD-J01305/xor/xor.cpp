#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[501000];
int andorl(int begin,int end){
	int sum=a[begin];
	for(int i=begin+1;i<=end;i++){
		sum=sum^a[i];
	}
	return sum;
}
void dfs(int m,int l){
	for(int i=l;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(andorl(i,j)==k){
				ans=max(ans,m);
				dfs(m+1,j+1);
			}
		} 
	}	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(1,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
