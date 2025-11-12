#include<bits/stdc++.h>
//#include<string>
//#include<algorithm>
//#include<cstdio>
//#include<>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	int s=1<<n;
	for(int i=7;i<s;i++){
		int maxn=0;
		int sum=0;
		int num=0;
		for(int j=0;j<n;j++){
			if((1<<j)&i){
				maxn=max(maxn,a[j]);
				sum+=a[j];
				num++;
			}
		}
		if(sum>maxn*2&&num>=3){
			ans++;
			if(ans==998244353){
				ans=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
