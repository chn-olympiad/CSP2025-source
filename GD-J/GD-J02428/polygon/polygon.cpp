#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long str;
set<int>s;
void dfs(int x,int i,int str){
	if(x>2*a[i]){
		s.insert(str);
	}
	else{ 
		for(int k=i+1;k<=n;k++){
			dfs(x+a[k],k,str*10+k);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],i,i);
	}
	cout<<s.size()%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
