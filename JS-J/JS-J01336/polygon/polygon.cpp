#include <bits/stdc++.h>
using namespace std;
int n,a[5100],b[5100],maxa,ans=0;
void dfs(int num){
	int add,numm=num;
	for(int j=n;j>=num;j--){
		for(int k=1;k<=num-1;k++){
			add+=a[k];
		}
		if(add>a[j])ans++;
		else{
			int l=numm;
			if(l<n)add=add-a[l]+a[l+1];
			else{
				add=add-a[n-1]+a[numm-1];
				numm++;
			}
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
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		maxa=max(a[1],a[2]);
		maxa=max(maxa,a[3]);
		if(a[1]+a[2]+a[3]>maxa*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	cout<<ans;
	return 0;
}
