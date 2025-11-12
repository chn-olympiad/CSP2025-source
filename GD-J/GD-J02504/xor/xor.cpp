#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],tx[25],ty[25];
long long pre[100100];
int n,k,num=0;
int f(int x,int y){
	int cnt=0,cnt2=0,t=1,sum=0;
	while(x){
		tx[cnt++]=x%2;
		x/=2;
	}
	while(y){
		ty[cnt2++]=y%2;
		y/=2;
	}
	for(int i=0;i<cnt;i++){
		if(i>=cnt2) ty[i]=0;
		if(tx[i]!=ty[i]) sum+=t;
		t*=2;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]>=a[i]? f(pre[i-1],a[i]):f(a[i],pre[i-1]);
		if(pre[i]==k&&b[1]==0) b[1]=i;
		if(a[i]==k) b[i]=i;
	}
	for(int i=2;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int t=pre[i-1]>=pre[j]? f(pre[i-1],pre[j]):f(pre[j],pre[i-1]);
			if(t==k){
				if(b[i]!=0){
					b[i]=min(b[i],j);
				}else{
					b[i]=j;
				}
			}
		}
	}
	int j=1;
	while(j<=n){
		if(b[j]){
			num++;
			j=b[j];	
		}
		j++;
	}
	cout<<num;
	return 0;
}
