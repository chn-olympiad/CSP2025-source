#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5100;
int a[N];
int v[N];
int n;
long long an=0;
void f(int x,int m,int y,int ma){
	if(y>n)
		return;
	if(x>2*ma && m>=3){
		an++;
		an=an%998244353;	
	}
	
	for(int i=y;i<=n;i++){
		if(v[i]==1)
			continue;
		v[i]=1;
		f(x+a[i],m+1,i,max(ma,a[i]));
		v[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
		f(a[i],1,i,a[i]);
	}
	cout<< an%998244353;
	return 0;
}
