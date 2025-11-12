#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int a[N],b[N],c[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<i;j++){
			int x=a[j]+a[i];
			int k=i+2;
			x-=a[i+1];
			if(x>0)ans++;
			ans%=MOD;
			while(x>0&&k<=n){
				x-=b[k];
                if(x>0){
                	ans++;
                	ans%=MOD;
				}
				k++;
			}
		}
		for(int j=1;j<i-1&&i>2;j++){
			int x=c[i]-c[j-1];
			int k=i+2;
			x-=a[i+1];
			if(x>0){
				ans++;
				ans%=MOD;
			}
			while(x>0&&k<=n){
				x-=b[k];
                if(x>0){
                	ans++;
                	ans%=MOD;
				}
				k++;
			}
		}
	}
	cout<<ans+2;
	return 0;
}
