/*ÖØ¶¨Ïò*/
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	
	cin>>n;
	//cout<<twopow(n);
	//return 0;
	if(n<3){
		cout<<0;
		return 0;
	}
	int a[n+7];
	for(int i = 0;i<n;++i)cin>>a[i];
	if(n==3){
		if(a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	sort(a,a+n);
	unsigned long long ans = 0; 
	for(int i = n-1;i>=2;--i){
		for(int j = i-1;j>=1;--j){
			for(int k=j-1;k>=0;--k){
				if(a[k]+a[j]>a[i]){
					ans+=(1<<(a[k]-1));
					ans%=mod;
					continue;
				}
			}
		} 
	}
	//unsigned long long ttt = 0;
	//for(int i = 0;i<n;++i){
		//ttt+=a[i];
	//}
	//if(ttt>a[n-1])++ans;
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
