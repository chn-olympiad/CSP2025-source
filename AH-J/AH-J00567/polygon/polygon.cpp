#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005]={0};
bool bj[100005]={0};
long long sum=0;
long long tot=0;
bool pd(int m){
	int ma=-1;
	for(int i=1;i<=m;i++){
		ma=max(ma,b[i]);
		tot+=b[i];
	}
	if(2*ma<tot){
		return 1;
	}
	return 0;
}
void print(int x){
	for(int i=1;i<=x;i++){
		
		cout<<b[i]<<" ";
	}
	cout<<endl;
}
void dfs(int k,int j){
	if(k>=3&&pd(k)){
		//print(k);
		sum++;
		sum=sum%998244353;
	}
	for(int i=j;i<=n;i++){
		if(bj[i]==0&&a[i]>=b[k-1]){
			b[k]=a[i];
			bj[i]=1;
			dfs(k+1,j+1);
			bj[i]=0;
			b[k]=0;
		}
	}
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(bj,0,sizeof(bj));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,1);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}
