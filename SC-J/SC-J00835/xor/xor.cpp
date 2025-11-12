#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005];
int n,k,ans=0;
ll wyh(int i,int j){
	ll res=a[i];
	i++;
	while(i<=j){
		res=res^a[i];
		i++;
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=f;j--){
			if(wyh(j,i)==k){
				ans++;
				f=i+1;
				j=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}