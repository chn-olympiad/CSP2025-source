#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int k;
int ans;
int x=1;
//long long f(int g){
//	long long o;
//	int y[25];
//	int l=1;
//	while(g){
//		y[l]=g%2;
//		g/=2;
//		l++;
//	}
//	for(int i=l;i>=1;i--){
//		o*=10;
//		o+=y[i];
//	}
//	return o;
//}
//long long xxor(int x,int y){
//	long long xx=f(x);
//	long long yy=f(y);
//	long long o;
//	int i[25];
//	int l=1;
//	while(xx){
//		int p=xx%10;
//		int q=yy%10;
//		if((p==0&&q==1)||(p==1&&q==0)){
//			i[l]=i[l]*10+1;
//		}else{
//			i[l]=i[l]*10;
//		}
//		xx/=10;
//		yy/=10;
//	}
//	int t=0;
//	int u=1;
//	for(int k=l;k>=1;k--){
//		o*=10;
//		o+=i[k];
//	}
//	while(o){
//		t=t+u*(o%10);
//		o/=10;
//		u*=2;
//	}
//	return t;
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	cin>>a[1];
	if(a[1]==k){
		ans++;
	}
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
		a[i]^=a[i-1];
	}
	int ff=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)ff=1;
	}
	if(!ff){
		cout<<n/k;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>k){
			for(int j=i;j>=x;j--){
				if(i!=j){
					if(a[i]&a[j]==k){
						ans++;
						x=i+1;
						break;
					}
				} 
			}
		}
	} 
	cout<<ans;
	return 0;
}