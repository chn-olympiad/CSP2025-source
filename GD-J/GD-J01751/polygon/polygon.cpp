#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long cnt=0;const int mo=998244353;int n,a[5005],ans[5005];bool one=1;
bool cmp(int x, int y){
	return (x>=y);
}
int pol(int dep,int maxi){
	if (maxi>n) return 0;
	if (dep>3){
		int sum=0;
		for (int i=1;i<dep;i++) sum+=ans[i];
		if (sum>2*ans[1]){
			sum=1;
			for (int i=maxi+1;i<=n;i++) sum=(sum*2)%mo;
			cnt=(cnt+sum)%mo;
			return 0; 
		}
	}
	for (int i=maxi+1;i<=n;i++){
		ans[dep]=a[i];
		pol(dep+1,i);
		ans[dep]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1) one=0;
	}
	if (one){
		cnt=1;
		for (int i=1;i<=n;i++) cnt=2*cnt%mo;
		cnt-=n+n*(n-1)/2+1;
		while (cnt<0){
			cnt+=mo;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	pol(1,0);
	cout<<cnt;
	return 0;
} 
