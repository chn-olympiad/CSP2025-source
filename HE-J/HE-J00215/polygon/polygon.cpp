#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5007,p=998244353;
long long a[N],n;
long long d(long long u,long long cnt,long long b){
	long long c=0;
	if(u==n){
		if(cnt>2*b){
			c++;
		}
		return c;
	}
	if(b==0x3f3f3f3f){
		c+=d(u+1,cnt+a[u],a[u]);
		c%=p;
	}
	else{
		c+=d(u+1,cnt+a[u],b);
		c%=p;
	}
	c+=d(u+1,cnt,b);
	c%=p;
	return c;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	cout<<d(0,0,0x3f3f3f3f);
	return 0;
} 
