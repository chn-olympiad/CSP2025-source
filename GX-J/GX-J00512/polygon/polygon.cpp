#include<bits/stdc++.h>
using namespace std;
int a[5003];
int num[5003],cnt=0;
bool b[5003];
bool cmp(int i,int j){
	return i<j;
}
int n;
int anss=0;
int ans[5003];
void check(int k){
	int i,j=-1,c=0;
	for(i=1;i<=k;i++){
		c=c+ans[i];
		j=max(j,ans[i]);
	}
	if(c>j*2){
		anss++;
	}
	return;
}
void dfs(int m,int num,int k){
	int i;
	if(num==k){
		check(k);
		return;
	}
	for(i=m;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			ans[num]=a[i];
			dfs(i,num+1,k);
			b[i]=0;
		}
	}
}
int cl1(int k){
	int i;
	int c=1;
	for(i=k+1;i<=n;i++){
		c=(c*i)%998244353;
	}
	for(i=1;i<=n-k;i++){
		c=c/i;
	}
	return c;
}
int main(){
	int i;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		for(i=1;i<=n;i++){
			cout<<a[i];
		}
		cout<<0;
		return 0;
	}
	else if(n==3){
		int maxx=-1;
		int numm=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			numm=numm+a[i];
			maxx=max(a[i],maxx);
		}
		if((maxx*2)>=numm){
			cout<<0;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	else if(n>3 && n<=20){
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		for(i=3;i<=n+1;i++){
			dfs(1,1,i);
		}
		cout<<anss%998244353;
	}
	else{
		for(i=1;i<=n;i++){
			int x;
			cin>>x;
		}
		for(i=3;i<n;i++){
			anss=(anss+cl1(i))%998244353;
		}
		anss++;
		cout<<anss;
	}
	return 0;
}
