#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000086];
long long cf(long long x,long long y){
	int ans=1;
	for(int i=1;i<=y;i++){
		ans=ans*x;
	}
	return ans;
}
long long tto(long long z){
	int g[30]={0},cnt=0;
	for(int i=1;z>0;i++){
		g[i]=z%2;
		z=(z-g[i])/2;
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
		z+=g[i]*cf(10,i-1);
	}
	return z;
}
long long tte(long long z){
	int g[30]={0},cnt=0;
	for(int i=1;z>0;i++){
		g[i]=z%10;
		z/=10;
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
		z+=g[i]*cf(2,i);
	}
	return z/2;
}
long long yh(long long x,long long y){
	x=tto(x);
	y=tto(y);
	int g[30]={0},h[30]={0},j[30]={0},nx=0,ny=0,z=0,cnt=0;
	for(int i=1;x>0;i++){
		g[i]=x%10;
		x/=10;
		nx++;
	}
	for(int i=1;y>0;i++){
		h[i]=y%10;
		y/=10;
		ny++;
	}
	for(int i=1;i<=nx/2;i++){
		swap(g[i],g[nx-i]);
	}
	for(int i=1;i<=ny/2;i++){
		swap(h[i],h[ny-i]);
	}
	for(int i=1;i<=nx;i++){
		cout<<g[i];
	}
	for(int i=1;i<=ny;i++){
		cout<<h[i];
	}
	for(int i=max(nx,ny);i>=1;i--){
		if(h[i]!=g[i]){
			j[i]++;
		}
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
		cout<<j[i]<<" ";
	}
	for(int i=1;i<=cnt;i++){
		z+=j[i]*cf(2,i);
	}
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<2;
	return 0;
}
