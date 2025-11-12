#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],b[5001],d,c[5001];
void go(long long h,int x){
	int l=0;
	for(int i=1;i<=n;i++){
		if(c[i]==1){
			if(h<=a[i]*2){
				l=1;
				break;
			}
		}
	}
	if(l==0&&x>=3){
		d++;
		d%=998244353;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==1)return;
		c[i]=1;
		go(h+a[i],x+1);
		c[i]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(b[1]==n){
		long long h=1;
		for(int i=3;i<=n;i++){
			h=1;
			for(int j=1;j<=i;j++){
				h*=(n-j+1);
				h/=j;
				h%=998244353;
			}
			d+=h;
			d%=998244353;
		}
		cout<<d;
		return 0;
	}
	sort(a+1,a+1+n);
	go(0,0);
	cout<<d%998244353;
	return 0;
}
