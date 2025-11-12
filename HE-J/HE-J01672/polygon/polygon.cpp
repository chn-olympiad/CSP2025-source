#include <bits/stdc++.h>
using namespace std;
int n,a[5010],maxn=-1,sum;
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){//i¸ùÄ¾¹÷ 
		for(int j=1;j<=i;j++){
			sum+=a[j];
			if(maxn<a[j]) a[j]=maxn;
			if(sum>maxn*2) cnt++;
		}
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
