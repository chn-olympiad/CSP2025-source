#include<bits/stdc++.h>
using namespace std;
int n,a[5005],l=3,ls[5005],s;
int dfs(int b,int nl){
	ls[b]=ls[b-1]+a[nl];
	//cout<<a[nl]<<' ';
	if(b==l){
		//cout<<endl;
		if(ls[b]>2*a[nl]){
			s++;
			//cout<<s<<endl;
			return 0;
		}
		return 0;
	}
	for(int i=nl+1;i<=n;i++){
		dfs(b+1,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(;l<=n;l++){
		for(int i=1;i<=n;i++){
			dfs(1,i);
		}
	}
	cout<<s;
	return 0;
}
