#include<bits/stdc++.h>
using namespace std;
int n;
long long s=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int a[n+5]={0},d[n+5]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=d[i-1]+a[i];
	}
/*
	for(int w=3;w<=n;w++){
		for(int r=w;r<=n;r++){
			int l=r-w+1,mx=0;
			long long cnt=d[r]-d[l-1];
			for(int i=l;i<=r;i++) mx=max(mx,a[i]);
			if(mx*2<cnt) s++;
			cout<<cnt<<" "<<" "<<mx<<endl;
		}
	}
	s%=998;
	s%=244;
	s%=353;
*/
	if(n==1||n==2) cout<<0;
	else if(n==3){
		int mx=0;
		long long cnt=d[3]-d[0];
		for(int i=1;i<=3;i++) mx=max(mx,a[i]);
		if(mx*2<cnt) cout<<1;
		else cout<<0;
	}
//	printf("%lld",s);
	return 0;
}
