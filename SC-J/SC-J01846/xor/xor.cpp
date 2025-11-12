#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int a[maxn],n,k,c;
bool f[maxn];
int yh(int a,int b){
	if(a==0||b==0) return max(a,b);
	if(a==b) return 0;
	int len1=0,len2=0,a1[30],b1[30],sum=0;
	memset(a1,0,30);
	memset(b1,0,30);
	while(a!=0){
		a1[++len1]=a%2;
		a/=2;
	}
	while(b!=0){
		b1[++len2]=b%2;
		b/=2;
	}
	int len=max(len1,len2);
	for(int i=len;i>=1;i--)
		if(a1[i]!=b1[i]) sum+=(1<<(i-1));
	return sum; 
}
int yhsum(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++) sum=yh(sum,a[i]);
	return sum; 
}
bool can(int l,int r){
	for(int i=l;i<=r;i++)
		if(f[i]==true) return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){cout<<n;return 0;}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(yhsum(l,r)==k&&can(l,r)){
				c++;
				for(int i=l;i<=r;i++) f[i]=true;
			}
		}
	}
	cout<<c;
	return 0;
}