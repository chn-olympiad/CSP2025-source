#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long t=0ll;
int c[5005];
bool check(int c[],int q){
	long long t1=0ll;
	int u=0;
	for(int i=1;i<=q;i++){
		u=max(u,c[i]);
		t1+=c[i];
	}
	if(t1>2*u)
		return true;
	else
		return false;
}
int dfs(int l,int f,int c[],int q){
	long long b=0ll;
	if(f==0&&check(c,q)){
		b++;	
		return b;
	}
	if(f==0||n-l+1<f)
		return 0;
	b+=dfs(l+1,f,c,q);
	c[++q]=a[l];
	b+=dfs(l+1,f-1,c,q+1);
	b%=998244353;
	return b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		t+=dfs(1,i,c,0);
		t%=998244353;
	}
	cout<<t;
	return 0;
}
