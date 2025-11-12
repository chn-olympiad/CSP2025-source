#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int a[N],c[40];
long long Xor(long long x,int y){
	int tot=0;
	while(x&&y){
		c[++tot]=(!(x%10)==(y%2));
		x/=10;
		y/=2;
	}
	while(x){
		c[++tot]=(x%10);
		x/=10;
	}
	while(y){
		c[++tot]=(y%2);
		y/=2;
	}
	long long n=0;
	for(int i=tot;i>=1;i--)n=n*10+c[i];
	return n;
}
long long xOr(int x){
	int tot=0;
	while(x){
		c[++tot]=x%2;
		x/=2;
	}
	long long n=0;
	for(int i=tot;i>=1;i--)n=n*10+c[i];
	return n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	k=xOr(k);
	for(int i=1;i<=n;i++)cin>>a[i];
	long long last=-1,cnt=0;
	for(int i=1;i<=n;i++){
		if(last==-1)last=xOr(a[i]);
		else last=Xor(last,a[i]);
		if(last==k){
			cnt++;
			last=-1;
		}
	}
	cout<<cnt;
	return 0;
}
