#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int cnt1;
int n,k,cnt0;
void solve1(){
	cout<<n/k;
	return ;
}
void solve0(){
	cout<<cnt1/k;
	return ;
}
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt0++;
	}
	if(cnt1==n) solve1();
	else if(cnt0+cnt1==n) solve0();
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
