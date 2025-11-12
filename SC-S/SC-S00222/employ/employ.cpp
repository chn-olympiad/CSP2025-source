#include<bits/stdc++.h>
using namespace std;
int n,m,d[505],sum1=0,c[505];
int calc(int a[],int c[],int d[]){
	int ac=0,bl=0;
	for(int i=0;i<n;i++){
		if(c[i] <=bl) {
			bl++;
		}else if(d[i] == 0){
			bl++;
		}else{
			ac++;
		}
	}
	return ac;
}
bool findnum(int a[],int b,int c){
	for(int i=0;i<b;i++){
		if(a[i]==c) return 0;
	}
	return 1;
}
int dfs(int a[],int ai,int c1[],int d1[]){
	if(ai==n){
		int t=calc(a,c1,d);
		if(t>=m) sum1++;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(findnum(a,ai,i)){
			a[ai] = i;
			c1[ai] = c[i];
			dfs(a,ai+1,c1,d1);
			a[ai] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a[505]={0};
	cin>>n>>m;
	char str[505];
	cin>>str;
	for(int i=0;i<n;i++){
		d[i] = str[i]-'0'; 
	}
	for(int i=0;i<n;i++) cin>>c[i];
	int c1[105],d1[105];
	dfs(a,0,c1,d1);
	cout<<sum1%998244353;
	return 0;
}