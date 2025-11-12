#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
long long n,k,num,ans=0,kk;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		int b;
		cin>>b;
		if(b==k){
			ans++;
		}else{
			kk++;
			a[kk]=b;
			if(b==0){
				num++;
			}
		}
	}
	sort(a+1,a+kk+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=n;j++){
			if(a[i]+a[j]==k){
				ans++;
				a[i]=99999999;
				a[j]=99999999;
				kk-=2;
				sort(a+1,a+kk+1);
			}
			if(a[i]-a[j]==k&&num>0){
				ans++;
				num--;
				a[i]=99999999;
				a[j]=99999999;
				kk-=2;
				sort(a+1,a+kk+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
