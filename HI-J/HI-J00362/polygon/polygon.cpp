#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m1 = 2; 
long long ans = 0;
void f(int st,int sum,int cnt){
	if(cnt==m1){
		for(int z = st;z<=n;z++){
			if(sum>a[z]){
				ans++;
			}
		}
		return;
	}
	for(int i = st;i<=n-1;i++){
		f(i+1,sum+a[i],cnt+1); 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(;m1<=n;m1++){
		f(1,0,0);
	}
	cout<<ans%998244353;
	return 0;	
}
