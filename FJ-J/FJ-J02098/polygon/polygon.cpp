#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int b[MAXN]= {0};
void pre(int a[],int l,int r) {
	b[l]=a[l];
	for(int i=l+1; i<=r; i++) {
		b[i]=a[i]+b[i-1];
	}
}
bool x(int a[],int l,int r) {
	sort(a+l,a+r+1);
	if(2*a[r]>=b[r]-b[l-1])return 0;
	else return 1;
}
bool f_q(bool vis[],int l,int r) {
	for(int i=l; i<=r; i++) {
		if(!vis[i])return true;
	}
	return false;
}
bool vis[500000]= {0};
int f(int n,int a[],int q,int ans,int l) {
	if(q==n+1)return ans;
	for(int i=l;i<=n;i++)
	{
		vis[i]=0;
	}
	for(int i=l; i<=n; i++) {
		if(x(a,i,i+q-1)&&f_q(vis,i,i+q-1)&&i+q-1<=n) {
			++ans;
			for(int j=i; j<=i+q-1; j++)vis[j]=1;
//			cout<<i<<" "<<i+q-1<<endl;
		}
	}
	return f(n,a,q+1,ans,l);
}
long long ncr(int n,int m) {
	long long sum=1;
	for(int i=m; i>m-n; i--) {
		sum*=i;
		sum=sum%998244353;
	}
	for(int i=n; i>0; i--) {
		sum/=i;
	}
	return sum;
}
long long kkk(int l,int r,int m) {
	long long sum=0;
	for(int i=l; i<=r; i++) {
		sum+=ncr(i,m);
		sum=sum%998244353;
	}
	return sum;
}
int main() {
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	int n;
	cin>>n;
	int a[n+1]= {0};
	int akcsp=-2147483640;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(akcsp<a[i])akcsp=a[i];
	}
	if(n==3) {
		if(max(max(a[1],a[2]),a[3])*2>=a[1]+a[2]+a[3])cout<<0;
		else cout<<1;
	} else if(akcsp==1) {
		cout<<kkk(3,n,n);
	} else {
		cout<<f(n,a,1,0,1);
	}
	return 0;
}

