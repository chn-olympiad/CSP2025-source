#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
int n,a[MAXN],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-3;i+=2){
		int maxn=-1,sum=0;
		for(int j=i+3;j<=n;j++){
			maxn=max(maxn,a[j]);
			sum+=a[j];
		}
		if(sum>2*maxn){
			cnt++;
		}
	}
	cnt%=998;
	cnt%=244;
	cnt%=353;
	cout<<cnt;
	return 0;
}