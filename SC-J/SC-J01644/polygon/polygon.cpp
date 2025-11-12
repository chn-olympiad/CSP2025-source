#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 998244353;
int a[100005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int sum=0;
	for(int i=3;i<=n;i++){
		if(a[i]>=b[i-1]) continue;
		sum++;
		int io=0;
		for(int j=i-1;j>0;j--) if(b[i-1]-a[j]>a[i]){
			io=j;
			break;
		}
		int cnt=b[io],ssum=io*(io+1)/2,l=1,r=0;
		if(io==i-1) cnt+=a[1];
		if(cnt==0) continue;
		while(b[i-1]-cnt<=a[i]){
			ssum--;
			if(cnt-a[l]>cnt-a[io-r]) cnt-=a[l],l++;
			else cnt-=a[io-r],r++;
		}
		sum+=ssum;
		sum%=N;
	}
	cout<<sum;
	return 0;
}
//