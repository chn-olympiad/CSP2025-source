#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
ll arr[N];
ll n,k,cnt,ans;
bool is;

void solve1(){
	cout<<n/2;
	return ;
}
void solve2(){
	if(k==1)
		for(int i=2;i<=n;){
//			cout<<ans<<' ';
			if(arr[i]!=arr[i-1]){
				ans++;
				i++;
			}
			i++;
		} 
	else 
		for(int i=2;i<=n;){
//			cout<<ans<<' ';
			if(arr[i]==arr[i-1]){
				ans++;
				i++;
			}
			i++;
		} 
	cout<<ans;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	is=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i>=2 && arr[i]!=arr[i-1]) is=1;
	}
//	cout<<is<<'\n';
	if(k==0 && !is) solve1();
	else if(is && (k==0 || k==1)) solve2();
	return 0;
}