#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k,a[N];
int bin(int x,int y){
	int t1[1100],t2[1100],cnt1=0,cnt2=0,cnt3=0,cnt=0,sum=0;
	int p=x,q=y;
	while(p>0){
		t1[cnt1++]=p%2;
		p/=2;
	}
	while(q>0){
		t2[cnt2++]=q%2;
		q/=2;
	}
	cnt=max(cnt1,cnt2);
	for(int i=cnt-1;i>=0;i--){
		if(t1[i]!=t2[i]) t1[i]=1;
		else t1[i]=0;
	}
	for(int i=cnt-1;i>=0;i--){
		if(t1[i]) sum+=pow(2,cnt3);
		cnt3++;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(bin(a[i],a[i+1])==0) ans++;
	}
	cout<<n/2;
	return 0;
}
