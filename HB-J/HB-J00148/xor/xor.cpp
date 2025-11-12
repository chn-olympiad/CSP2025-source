#include<bits/stdc++.h>
#define For(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int a[1145149];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int f=1;
	For(i,1,n){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f==1){
		cout<<n/2;
		return 0;
	}
	int ans=0;
	if(k==0){
		For(i,1,n){
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
			if(a[i]==0)ans++;
		}
	}else if(k==1){
		For(i,1,n){
			if(a[i]==1)ans++;
		}
	}
	cout<<ans;
	return 0;
}
