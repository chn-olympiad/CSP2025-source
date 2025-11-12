#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,k,ans=0,a[N];
bool flag1=0,flag2=0;
void check0(){
	for (int i=1;i<n;i++){
		if (a[i]==a[i+1]){
			ans++;
			i++;
		}
	}
	return;
}
void check1(){
	if (k==0){
		check0();
		return;
	}
	for (int i=1;i<=n;i++){
		if (a[i]==1){
			ans++;
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1) flag1=1;
		if (a[i]>1) flag2=1;
	}
	if (flag1==0){
		cout<<n/2;
		return 0;
	}
	if (flag2==0){
		check1();
		cout<<ans;
		return 0;
	}
	long long sum=0,p=0;
	for (int i=1;i<=n;i++){
		sum^=a[i];
		long long temp=sum,j=p+1;
		while(temp!=k && j<i){
			temp^=a[j];
			j++;
		}
		if (temp==k){
			ans++;
			sum=0;
			p=i;
		}
	}
	cout<<ans;
	return 0;
}
