#include<bits/stdc++.h>
using namespace std;
long long n,k,arr[500005],sum[500005],cnt,z;
struct node{
	long long l,r;
}a[500005];
bool cmp(node x,node y){
	if(x.r!=y.r)
	return x.r<y.r;
	return x.l<x.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		sum[i]=sum[i-1]^arr[i];
		if(arr[i]==k){
			a[z].l=i;
			a[z++].r=i; 
		}
		if(sum[i]==k){
			a[z].l=1;
			a[z++].r=i; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				a[z].l=i;
				a[z++].r=j;
				break;
			}
		}
	}
	sort(a,a+z,cmp);
	node temp=a[0];
	cnt=1;
	for(int i=1;i<z;i++){
		if(a[i].l>temp.r){
			temp=a[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}