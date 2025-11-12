#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int a[N];
int nn;
int dfs(int i,int maxl,int sum){
	//cout<<maxl<<" "<<" "<<sum<<endl;
	if(i>n){
		if(sum>maxl*2){
			nn++;
		}
		return 0;
	}
	dfs(i+1,max(maxl,a[i]),sum+a[i]);
	dfs(i+1,maxl,sum);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		cout<<((aa+bb)>cc)&&((bb+cc)>aa)&&((aa+cc)>bb);
	}
	else{
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=1)f=1;
		}
		if(!f){
			long long ans=1,sum=0;
			int k=n;
			for(int i=1;i<=n;i++){
				ans=ans*k;
				sum+=ans;
				sum=sum%998244353;
				k--;
			}
			cout<<sum;
		}
		else{
			dfs(1,0,0);
			cout<<nn;
		}
	}
	
	return 0;
}
