#include<bits/stdc++.h>
using namespace std;
int n,m;
int cj;
int k,mc;
int a[105];
int ans1,ans2;
int fz;//第几组 
int xf;//第fz组第几个 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(cj==a[i]){
			mc=i;
			break;
		}
	}
	fz=(mc-1)/(2*n)+1;//1~m
	xf=(mc-1)%(2*n)+1;
	if(xf<=n){
		ans1=xf;
		ans2=(fz-1)*2+1;
	}
	else if(xf>n){
		ans1=(n*2+1)-xf;
		ans2=fz*2;
	}
	cout<<ans2<<" "<<ans1;
	return 0;
}
