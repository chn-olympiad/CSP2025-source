#include <bits/stdc++.h>
using namespace std;

const int N=5010;
int n,sum;
int a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==3){
		int maxn=max(max(a[1],a[2]),a[3]);
		if(sum>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		int maxn1=max(max(max(a[1],a[2]),a[3]),a[4])*2;
		int maxn2=max(max(a[1],a[2]),a[3])*2;
		int maxn3=max(max(a[1],a[2]),a[4])*2;
		int maxn4=max(max(a[2],a[3]),a[4])*2;
		int sum2=a[1]+a[2]+a[3];
		int sum3=a[1]+a[2]+a[4];
		int sum4=a[2]+a[3]+a[4];
		int cnt=0;
		if(sum2>maxn2) cnt++;
		if(sum3>maxn3) cnt++;
		if(sum4>maxn4) cnt++;
		if(sum>maxn1) cnt++;
		cout<<cnt;
		return 0;
	}
	return 0;
}
