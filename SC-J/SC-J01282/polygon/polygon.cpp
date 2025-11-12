#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],sum,b[10005];
void dfs(long long dq,long long cnt,long long x){
	if(cnt==x){
		long long h=0,mx=-1e9;
		for(int y=1;y<=x;y++){
			h+=a[y];
			if(a[y]>mx){
				mx=a[y];
			}
		}
		if(h>mx*2){
			sum++;
		}
		return;
	}
	for(int y=dq+1;y<=n;y++){
		a[cnt+1]=b[y];
		dfs(y,cnt+1,x);
		a[cnt+1]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			a[1]=b[j];
			dfs(j,1,i);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}