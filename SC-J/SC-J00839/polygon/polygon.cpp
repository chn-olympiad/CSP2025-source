#include<bits/stdc++.h>
using namespace std;
int sum,maxx,ans;
int n,a[10001];
int ww,b[10001],bb;
void polygon(int w,int c){
	if(c==1){
		sum+=a[w];
		int j=maxx;
		maxx=max(maxx,a[w]);
		if(maxx*2<sum){
			ans=(ans+1)%998244353;
		}
		sum-=a[w];
		maxx=j;
		return;
	}
	else{
		sum+=a[w];
		int j=maxx;
		maxx=max(maxx,a[w]);
		for(int i=w+1;i<=n-c+2;i++){
			polygon(i,c-1);
		}
		sum-=a[w];
		maxx=j;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int y=1;y<=n-i+1;y++){
			sum=0,maxx=-1;
			polygon(y,i);
		}
	}
	cout<<ans;
	return 0;
} 