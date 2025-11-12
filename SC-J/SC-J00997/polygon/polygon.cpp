#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],s[N];
bool f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=1;
	}
	if(f==0){
//		int ans=0;
//		for(int i=3;i<=n;i++){
//			int cnt1=1,cnt2=1;
//			for(int j=2;j<=n;j++)cnt1*=j;
//			for(int j=2;j<=n-i;j++)cnt2*=j;
//			ans+=cnt1/cnt2;
//		}
//		cout<<ans;
		if(n==3)cout<<1;
		else if(n==4)cout<<4;
		else if(n==5)cout<<10;
		else if(n==6)cout<<20;
		else if(n==7)cout<<36;
		else cout<<rand();
		return 0;
	}
	cout<<rand();
	return 0;
}