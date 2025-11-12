#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000010];
int cnt1,cnt0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
	}
	if(cnt1==n&&k==1) {
		cout<<n;
		return 0;
	}
	else if(cnt1==n&&k!=0){
		cout<<"0";
		return 0;
	}
	else if(cnt1==n&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(cnt0==n&&k==0){
		cout<<n;
		return 0;
	}
	else if(cnt0==0&&k!=0){
		cout<<"0";
		return 0;
	}
	int cnt=0;
	for(int i=1; i<=n; i++) {
		long long s=a[i];
		if(s==k) {
			cnt++;
			continue;
			//cout<<"1"<<" "<<i<<endl;
		}
		for(int j=i+1; j<=n; j++) {
			s=s^a[j];
			if(s==k){
				cnt++;
				i=j;
				break;
				//cout<<"2"<<" "<<i<<j<<endl;	
			} 
		}
	}
	cout<<cnt;
	return 0;
}
