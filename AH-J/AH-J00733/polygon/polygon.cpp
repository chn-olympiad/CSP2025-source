#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10010]={0};
long long h=0;
void dfs(long long s,long long k){
	if(k<0){
		h++;
	}
	for(int j=s+1;j<n;j++){
		dfs(j,k-a[j]);
	}
	return ;
}
int cmp(int aaa,int bbb){
	if(aaa>=bbb){
		return 1;
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		dfs(i,a[i]);
	}
	cout<<h;
	return 0;
}
