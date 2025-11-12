#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[5009];
bool b[5009];
long long k=998244353;
long long ans=0;
int m=0;
int n;

long long f(int c){
	long long z=1;
	for(int j=0;j<c;j++){
		z*=2;
		z%k;
	}
	return z;
}

int g(int x,int y){
	if(y>=m){
		ans+=f(n-x-2)-n+x+2%k;
		return 0;
	}
	for(int j=1;j<=n-2;j++){
		if(b[j]==0){
			b[j]==1;
			g(x+1,y+a[j]);
			b[j]==0;
		}
	}
	return 0;
}

int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","w",stdout);
	

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	sort(a+1,a+n+1);
	m*=2;
	m=m-a[n]-a[n-1];
	g(0,0);
	cout<<ans<<endl;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

