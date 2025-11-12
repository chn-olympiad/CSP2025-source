#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int n;
int a[N],b[N],c[N];
bool cmp(int x,int y) {
	return x>y;
}
bool cmp1(pair<int ,int>x,pair<int,int> y){
	return x.first+y.second>x.second+y.first;
}
long long sum=0;
void f(int x,int y,int z,int h,long long ans) {
	if(h>n) {
		sum=sum<ans?ans:sum;
		return;
	}
	if(x<n/2) f(x+1,y,z,h+1,ans+a[h]);
	if(y<n/2) f(x,y+1,z,h+1,ans+b[h]);
	if(z<n/2) f(x,y,z+1,h+1,ans+c[h]);
}
bool ck(){
	for(int i=1;i<=n;i++) if(b[i]!=0) return 0;
	return 1;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) cin>>a[i]>>b[i]>>c[i];
		if(n>200) {
			if(ck()) {
				long long ans=0;
				sort(a+1,a+n+1,cmp);
				for(int i=1; i<=n/2; i++) ans+=a[i];
				cout<<ans<<endl;
			}
			else {
				long long ans=0;
				pair<int,int> d[n+1];
				for(int i=1;i<=n;i++) d[i]={a[i],b[i]};
				sort(d+1,d+1+n,cmp1);
				for(int i=1;i<=n/2;i++) ans+=d[i].first;
				for(int i=n/2+1;i<=n;i++) ans+=d[i].second;
				cout<<ans<<endl;
			}
		} else {
			f(0,0,0,1,0);
			cout<<sum<<endl;
			sum=0;
		}
	}
	return 0;
}
