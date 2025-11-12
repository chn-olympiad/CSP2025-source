#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,s,cnt;
int a[N];
bool fa=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]) fa=0;
	}
	if(fa){
		if(k==0) cout<<n/2;
		else if(k==a[1]) cout<<n;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s=a[i];
		while(s!=k&&i<=n){
			i++;
			s^=a[i];
		}
		if(s==k) cnt++;
	}
	cout<<cnt;
	return 0;
}
