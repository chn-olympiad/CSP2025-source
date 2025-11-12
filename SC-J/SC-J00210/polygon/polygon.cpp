#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool dppp=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=2){
			dppp=false;
		}
	}
	if(n<=3){
		if(n<=2){
			cout<<0;
			return 0;
		}else{
			int xpop=max(a[1],max(a[2],a[3]));
			if(a[1]+a[2]+a[3]>2*xpop){
				cout<<1;
			}else{
				cout<<0;
			}
			return 0;
		}
		
	}
	if(dppp){
		long long sum=1,sum1=1;
		int cnt1=1,cnt=1;
		sort(a+1,a+1+n);
		while(!a[cnt]){
			if(cnt>1){
				sum=sum*3%998244353;
			}
			cnt++;
		}
		cnt1=cnt-1;
		while(a[cnt]&&cnt<=n){
			if(cnt-cnt1>4){
				sum1=sum1*3%998244353;
			}
			cnt++;
		}
		if(cnt-cnt1<=3){
			cout<<0;
			return 0;
		}else if(cnt-cnt1>=4){
			cout<<sum1*sum%998244353;
			return 0;
		}
	}
	return 0;
}