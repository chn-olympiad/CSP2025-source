#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500001];
int ff(int u){
	int dd=0,i=0;
	while(u!=0){
		dd+=u%10*pow(2,i);
		u/=10;
		i++;
	}
	return dd;
}
int xo(int x,int y){
	int m[100001],t[100001];
	int i=0;
	while(x!=0){
		m[i]=x%2;
		x/=2;
		i++;
	}
	int j=0;
	while(y!=0){
		t[j]=y%2;
		y/=2;
		j++;
	}
	int m1=max(i,j),ans=0,cmp=0;
	for(int h=m1-1;h>=0;h--){
		if(m[h]==1&&t[h]==1)ans=ans*10+1;
		else if(m[h]==1||t[h]==1)cmp=cmp*10+1;
		else ans*=10,cmp*=10;
	}
	return ff(ans)+ff(cmp);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){cin>>a[i];}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)if(xo(a[i],a[j])==k)ans++;
		
	cout<<ans+1;
	return 0;
}
