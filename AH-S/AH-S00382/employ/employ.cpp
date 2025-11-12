#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1,b;i<=n;i++){
		cin>>b;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=cnt){
			n--;
			cnt++;
		}
	}
	long long sum=1;
	for(int i=0;i<=m-1;i++){
		sum*=n-i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
