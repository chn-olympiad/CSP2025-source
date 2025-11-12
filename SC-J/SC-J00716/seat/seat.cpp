#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt,a[1005],ans;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	int s=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		s++;
		if(cnt==a[i]){
			ans=s;
			cnt=s;
			break;
		}
	}
	if(ans%n==0&&ans/n%2!=0){
		cout<<ans/n<<" "<<m;
	}
	if(ans%n==0&&ans/n%2==0){
		cout<<ans/n<<" "<<1;
	}
	if(ans%n!=0&&ans/n%2!=0){
		ans/=n;
		ans++;
		cout<<ans<<" "<<n-(cnt%n)+1;
	}
	if(ans%n!=0&&ans/n%2==0){
		ans/=n;
		ans++;
		cout<<ans<<" "<<cnt%n;
	}
	return 0;
}
