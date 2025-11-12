#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	int maxn=0;
	int cnt=0;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=0;i<n;i++){
		if(maxn<a[i]){
			maxn=a[i];
		}
	}
	if(n==3 && sum>maxn*2){
		cout<<1;
	}
	else if(n==3 && sum<=maxn*2){
		cout<<0;
	}
	else if(n>2 && maxn<=1){
		for(int i=3;i<=n;i++){
			cnt++;
		}
		if(cnt>998){
			cout<<cnt%998;
		}
		else if(cnt>353){
			cout<<cnt%353;
		}
		else if(cnt>244){
			cout<<cnt%244;
		}
	}
	return 0;
}
