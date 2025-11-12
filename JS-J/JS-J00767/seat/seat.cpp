#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long a[n*m];
	for(int i=0;i<n*m;i++) cin>>a[i];
	long long tmp=a[0],ans;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
		if(a[i]==tmp){
			ans=i+1;
			break;
		}
	if(ans%n==0){
		if((ans/n)%2!=0) cout<<ans/n<<' '<<n;
		else cout<<ans/n<<' '<<1;
	}
	else{
		if((ans/n)%2==0) cout<<ans/n+1<<' '<<ans%n;
		else cout<<ans/n+1<<' '<<n-(ans%n)+1;
	}
	return 0;
}
