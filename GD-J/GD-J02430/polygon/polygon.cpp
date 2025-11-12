#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans=0;
bool cmp(int temp[],int step){
	int maxx=-1,sum=0;
	for(int i=1;i<=step;i++){
		maxx=max(maxx,a[temp[i]]);
		sum+=a[temp[i]]; 
	}
	if(2*maxx<sum) return true;
	else return false;
}
void dfs(int id,int step,int maxx,int sum){
	if(id>n and step>=3){
		if(maxx*2<sum and maxx!=-1 and sum!=0){
			ans++;
		}
		return ;
	}
	if(id>n and step<3) return ;
	dfs(id+1,step,maxx,sum);dfs(id+1,step+1,max(maxx,a[id]),sum+=a[id]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int temp[5010];
	dfs(1,0,-1,0);
	cout<<ans%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
