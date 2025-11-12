#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10;
const long long md=998244353;
int l[N],st[N];
long long C(int a,int b){
	if(a==b){
		return 1;
	}
	else{
		long long ans=1;
		for(int i=a;i>b;i--){
			ans*=i;
		}
		for(int i=1;i<=a-b;i++){
			ans/=i;
		}
		return ans;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);		
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	if(n==3){
		int count=0;
		for(int i=1;i<=3;i++){
			count+=l[i];
		}
		if(count>l[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(l[n]==1){
		long long ans=0;
		for(int i=n;i>=3;i--){
			ans+=C(n,i);
			ans%=md;
		}
		cout<<ans;
		
		return 0;
	}
	long long count=0;
	for(int i=n;i>=3;i--){
		count+=C(n,i);
		count%=md;
	}
	cout<<count%md;
	
	return 0;
}
