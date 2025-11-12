#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt,v[5005],b[5005];
void dfs(int step,int w){
	if(step>w){
		int sum=0;
		for(int i=1;i<=w;i++){
			sum+=b[i];
		}
 		if(sum>b[w]*2){
 			cnt++;
		}
		return ;
	}
	for(int i=step;i<=n;i++){
		if(v[a[i]]==0){
			v[a[i]]=1;
			b[i]=a[i];
			dfs(step+1,w);
			v[a[i]]=0;
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
		dfs(1,i);
	}
	cout<<cnt/3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
