#include<iostream> 
using namespace std;
int a[1005],sum=0,maxn=-1,ans=0;
int jc(int x){
	int y=1;
	for(int i=1;i<=x;i++){
		y*=i;
	}
	return y;
}
int A(int m,int n){
	return jc(n)/jc(n-m);
} 
int C(int m,int n){
	return A(m,n)/jc(m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum==n){
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=C(i,n);
		}
		cout<<cnt;
		return 0;
	}else if(sum>2*maxn){
		cout<<1;
	}else{
		cout<<0;
	}
}
