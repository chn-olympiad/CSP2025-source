#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],k;
int n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=1;
		}
	}
	if(!f){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		int ans=0;
		int i=1;
		while(i<=n){
			if(a[i]==a[i+1]){
				ans++;
				i++;
			}
			i++;
		}
		int sum=0;
		for(int i=1;i<=n;i++)if(a[i]==k)sum++;
		cout<<max(sum,ans);
	}
	else{
		int ans=0;
		int i=1;
		while(i<=n){
			if(a[i]!=a[i+1]){
				ans++;
				i++;
			}
			i++;
		}
		int sum=0;
		for(int i=1;i<=n;i++)if(a[i]==k)sum++;
		cout<<max(sum,ans);
	}
	return 0;
}