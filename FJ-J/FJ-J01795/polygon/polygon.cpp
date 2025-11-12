#include<bits/stdc++.h>
using namespace std;
int n;
int a[5020];
int ans=0;
void f(int he,int maxx,int yong,int q) {
	if(yong>=3&&2*maxx<he) {
		ans=(ans+1)%9982244353;
	}
	for(int i=q; i<=n; i++) {
		he+=a[i];
		int t=maxx;
		int tt=q;
		maxx=max(maxx,a[i]);
		yong+=1;
		q=i+1;
		f(he,maxx,yong,q);
		he-=a[i];
		maxx=t;
		yong-=1;
		q=tt;
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	f(0,0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
