#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum,t,a[50100];
char s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    sum=max(sum,a[i]);
	}
	if(n<=2){
	cout<<"0";
	}
	if(n==3){
	if(a[1]+a[2]+a[3]>2*sum){
	cout<<"1";
	}	}
	if(sum==1){
		ans=n;
		long long ans1=0,sum1=n,sum2=1,ans2=1;
		for(int i=2;i<=n;i++){
			sum1--;
			sum2++;
			if(i>=3){
			ans1+=ans1*sum1/sum2;
			ans1%=998244353;
			}
		}
		cout<<ans1;
	}

	cout<<endl;
	return 0;
}
