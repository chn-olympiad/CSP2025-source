#include<bits/stdc++.h>
using namespace std;
struct hi{
	long long star;
	long long end;
}hello[5000001];
bool f2(hi x,hi y){
	if(x.end==y.end)return x.star>y.star;
	return x.end<y.end;
}
	long long n,k,a[5000001],top=1,ans=0;
long long f(long long ll,long long rr){
	return a[rr]^a[ll-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//前缀和 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	//求区间 
	for(long long i=1;i<=n;i++)
		for(long long j=i;j<=n;j++)
			if(f(i,j)==k){
				hello[top].star=i;
				hello[top].end=j;
				top++;
			}
	//排序 
	sort(hello+1,hello+top,f2);
	//找出最多区间 
	long long l,r,k=1;
	ans++;
	for(;k<=n;){
		long long i;
		for(i=k;hello[i].star<=hello[k].end&&k<=n;i++);
		k=i;
		if(k<=n)ans++;
	}
	//QED 
	cout<<ans;
	return 0;
}
