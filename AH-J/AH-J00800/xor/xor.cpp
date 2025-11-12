#include<bits/stdc++.h>
using namespace std;
int arr[5000010];
long long n,k,sum,hi=0,qi,cnt;
struct zb{
	int s,e;
}his[250000000];
bool cmp(zb q,zb w){
	if(q.s==w.s){
		return q.e<w.e;
	}
	return q.s<w.s;
}
void pan(int q,int w){
	if(q==w){
		if(arr[q]==k){
			hi++;
			his[hi].s=q;
			his[hi].e=q;
		}
		return ;
	}
	sum=arr[q];
	for(int i=q+1;i<=w;i++){
		sum^=arr[i];
	}
	if(sum==k){
		hi++;
		his[hi].s=q;
		his[hi].e=w;
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			pan(i,j);
		}
	}
	sort(his+1,his+1+hi,cmp);
	for(int i=his[1].s;i<=n;i=his[i].e+1){
		cnt++;
	}
	cout<<cnt;
	return 0;
}
