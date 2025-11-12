#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ma=-1,shu,z,he1,i1,biao;
void dfs(int st,int he){
	if(he==z) return;
	for(int i=st;i<=n;){
		he1=he+a[i];
		i1=i;
		++i;
			
			if(he1>a[i1]*2){
				++shu;
			}
			dfs(i,he1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z=z+a[i];
	}
	sort(a,a+n+1);
	for(int i=2;i<=n-1;i++){
		dfs(i,a[i-1]);
	}
	cout<<shu;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}