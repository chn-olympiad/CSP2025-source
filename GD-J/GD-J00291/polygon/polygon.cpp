#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+10;
int n,a[N],ans,bo[N];
int find(int k,int l,int h){
	if(k==0) return 1;
	int an=0;
	for(int i=l;i<=n-k+1;i++){
		if(an<=a[i]&&h==0) return an;
		else an+=find(--k,i+1,0);
	}
	return an;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]<a[1]+a[2]) cout<<1;
		 else cout<<0;
		return 0;
	}
	for(int j=3;j<=n;j++)
		ans+=find(j,1,1);
	cout<<ans;
	return 0;
}
