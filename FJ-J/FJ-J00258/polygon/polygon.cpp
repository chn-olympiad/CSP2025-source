#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int po(int p,int t,int maxx,long long sum){
	long long re=0;
	int ma;
	for(int i=p;i<=n;i++){
		ma=max(maxx,a[i]);
		if(t+1>=3&&2*ma<sum+a[i])re++;
		re%=998244353;
		re+=po(i+1,t+1,ma,sum+a[i]);
		re%=998244353;
		//cout<<p<<' '<<t<<endl;
	}
	return re;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	//sort(a+1,a+n+1);
	cout<<po(1,0,0,0);
	return 0;
}
