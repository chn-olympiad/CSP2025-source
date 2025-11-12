#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5005],s[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=3;i<=n;i++){
		int x=a[i];
		for(int j=1;j<i;j++){
			if(s[j]>x){
				int len=i-j-1;
				int cnt=0;
				if(len==1)ans+=j;
				ans+=(j*len)+1;
				ans%=M;
				for(int k=len-1;k>=2;k--){
					ans+=(++cnt)*k;
					ans%=M;
				}
				for(int k=1;k<=min(j,len);k++){
					ans+=(len-k+1)*len/2*(j-k+1)*j/2;
					ans%=M;
				}
			}
		}
	}
	cout<<ans;
}
