#include<bits/stdc++.h>
using namespace std;
int a[5001],n,ans=0;
int qiuhe(int start,int end){
	int sum=0;
	for(int i=start;i<=end;i++){
		sum+=a[i];
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=1;i<=n-1-cnt;i++){
		if(cnt==n){
			break;
		}
		int he=qiuhe(i,i+cnt);
		for(int j=i+cnt+1;j<=n;j++){
			if(he+a[j]>2*a[j]){
				cout<<he+a[j]<<' '<<2*a[j]<<'\n';
				ans++;
				ans%=998244353;
			}
		}
		if(i==n-cnt-1){
			i=1;cnt++;
		}
	}
	cout<<ans;
	return 0;
}

