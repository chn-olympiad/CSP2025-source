#include<bits/stdc++.h>
using namespace std;
int n,a[5005],d;
long long c;
bool cmp(int x,int y){
	return x>y;
}
void f(int x,int y,int z){
	if(x==n){
		if(y>d&&z>=3){
			c++;
			c%=998244353;
		}
		return;
	}
	f(x+1,y,z);
	f(x+1,y+a[x],z+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int g=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1){
			g=1;
		}
	}
	c=0;
	if(g==0){
		long long ff=2;
		c=2;
		for(int i=2;i<=n;i++){
			ff*=2;
			c+=i;
			c%=998244353;
		}
		ff%=998244353;
		ff-=c;
		cout<<ff;
		return 0;
	}
	sort(a,a+n,cmp);
	for(int i=n-3;i>=0;i--){
		d=a[i]*2;
		f(i+1,a[i],1);
	}
	cout<<c;
	return 0;
}
