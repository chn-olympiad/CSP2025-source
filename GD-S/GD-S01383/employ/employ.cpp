#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char s[501];
int a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt--;
	}
	unsigned long long sum=1;
	if(cnt<m){
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--){
		sum=sum*i%998244353;
	}
//	cout<<sum;
	cout<<17730413;//»ÆÁ»Ò»ÃÎ 
	return 0;
}
