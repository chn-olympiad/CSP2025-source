#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];

bool cmp(int a,int b){
	return a>b;
}

long jie(int i){
	if(i==1){
		return 1;
	}
	return i*jie(i-1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	int cnt=0;
	int mx=a[1];
	if(n<=3){
		if(sum>mx*2){
			ans=1;
			cout<<ans%998244353;
		}
		return 0;
	}else if(mx==1){
		int m;
		for(int i=n-2;i>=1;i--){
			m=n-i+1;
			sum=i;
			for(int j=n;j>i;j--){
				sum*=j;
			}
			sum/=jie(m);
			ans+=sum;
		}
		cout<<ans%998244353;
		return 0;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		mx=a[i];
		for(int j=n;j>=i;j--){
			sum+=a[j];
			cnt++;
		}
		if(cnt<3)continue;
		else if(sum>mx*2)ans++;
	}
	cout<<ans%998244353;
	return 0;
}
