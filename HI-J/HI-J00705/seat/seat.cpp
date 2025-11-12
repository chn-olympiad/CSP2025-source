#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int num=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		c++;
		int ans,sum;
		if(a[i]==num){
			if(c%2!=0) ans=c/m+1;
			else if(c%2==0) ans=c/m;
			if(ans%2==1){
				sum=c%n;
				if(sum==0) sum=c;
			}
			else if(ans%2==0) sum=n-c%n+1;
			cout<<ans<<' '<<sum;
		}
	}
	return 0;
}
