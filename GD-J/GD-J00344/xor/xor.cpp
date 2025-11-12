#include<bits/stdc++.h>
using namespace std;
int n,k,m=0;
int a[500002];
int f(int x,int s){
	if(x==n) return s;
	int t=a[x],i;
	if(t==k) return f(x+1,s+1);
	for(i=x+1;i<=n;i++){
		t=t^a[i];
		if(t==k) return f(i+1,s+1);
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		m=max(m,f(i,0));
	}
	cout<<m;
	freopen("xor.out","w",stdout);
	return 0;
} 
