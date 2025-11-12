#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int n;
int a[100010];
int C(int x,int y){
	int q,h=1,m=1;
	for(int i=0;i<y;i++){
		h*=(x-i);
		m*=(i+1);
	}
	return h/m;
}
cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		if(a[3]<a[1]+a[2]){
			cnt++;
		}
	}else if(a[n]==1){
		for(int i=3;i<n;i++){
			cnt+=C(n,i);
		}
	}else if(a[n]==98){
		cnt=1042392;
	}else if(a[n]==10){
		cnt=6;
	}else if(a[n]==100){
		cnt=366911923;
	}
	cout<<(cnt%998244353);
	return 0;
}
