#include<bits/stdc++.h>
using namespace std;
long long  n;
long long a[5001],ans[5001]={0},sum=0,l=0,k=0;
void dfs(long long x){
	if(x>l){
		int maxx=0;
		for(long long i=1;i<=l;i++){
			if(a[ans[i]]>maxx)maxx=a[ans[i]];
			sum+=a[ans[i]];
		}
		if(sum>(2*maxx)){
			k++;
			//cout<<sum<<' ';
			//for(int i=1;i<=l;i++)cout<<ans[i]<<' ';
			//cout<<endl;
		}
		sum=0;
		return;
	}
	for(long long i=ans[x-1]+1;i<=n;i++){
		ans[x]=i;
		dfs(x+1);
		ans[x]=0; 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(long long i=3;i<=n;i++){
		l=i;
		sum=0;
		dfs(1);
		
	} 
	cout<<k%998244353;
	return 0;
}
