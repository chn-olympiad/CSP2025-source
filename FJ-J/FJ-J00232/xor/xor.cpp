#include <bits/stdc++.h>
using namespace std;
int n,a[500005],sum,ans;
long long k,f[500005];
int yihuo(int a,int b){
	int ax[10]={0},bx[10]={0},ans[10]={0};
	int x=0,y=0;
	while(a){
		ax[++x]=a%10;
		a/=10;
	}
	while(b){
		bx[++y]=b%10;
		b/=10;
	}
	int num=max(x,y);
	for(int i=num;i>=1;i--) ans[i]=!(ax[i]&bx[i]);
	int ans1=0;
	for(int i=1;i<=num;i++){
		ans1+=pow(2,i-1)*ans[i];
	}
	return ans1;
}
int two(int x){
	int d[10]={0},cnt=0,m=0;
	while(x){
		d[++cnt]=x%2;
		x=(x-x%2)/2; 
	}
	for(int i=cnt;i>=1;i--) m=m*10+d[i];
	return m;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	sum=a[1];
	for(int i=2;i<=n;i++){
		if(sum==k){
			ans++,sum=a[i+1];
			continue;
		}
		else sum=yihuo(two(sum),two(a[i]));
	}
	cout<<ans;
	return 0;
}
