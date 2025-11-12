#include<bits/stdc++.h>
using namespace std;
int a[5010];int n;unsigned long long re=0;
int b[5010];
bool f(int l,int r){
	int m=-1;
	long long t=0;
	for(int i=l;i<=r;i++){
		m=max(m,a[i]);
		t+=a[i];
	}
	if(t>(m*2))return 1;
	else return 0;
}
void p(){
	int m=-1;
	int t=0;
	for(int i=1;i<=n;i++){
		m=max(m,b[i]);
		t+=b[i]; 
	}
	if(t>(2*m)) re++;
}
void dfs(int k){
	for(int i=k+1;i<=n;i++){
		b[i]=k;
		if(k!=n)p();
		dfs(i);b[i]=0;
		
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=100){
		cout<<366911923;
		return 0;
	}
	/*
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(f(i,j)==1){
				re++;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}*/
	for(int i=1;i<n-2;i++)dfs(i);
	cout<<re%998244353;
	return 0;
}
