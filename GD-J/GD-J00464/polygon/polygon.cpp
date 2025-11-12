#include<bits/stdc++.h>
using namespace std;
int n,a[10000],cnt;
bool qsy=true;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) qsy=false;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(qsy){
		int cheng,chu;
		for(int i=3;i<=n;i++){
			for(int j=n;j>n-i;j--){
				cheng*=j;
				cheng=cheng%998244353;
			}
			for(int j=2;j<=i;j++){
				chu/=j;
				chu=chu%9982447353;
			}
			cnt=cnt+cheng/chu;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
