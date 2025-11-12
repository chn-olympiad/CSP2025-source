#include <bits/stdc++.h>
using namespace std;
int n,a[5005],two[5005],sum,cnt,ans[5005];
bool pd(int x){
	int sum1=0,maxn=-1;
	for (int i=1;i<=x;i++){
		sum1+=ans[i];
		maxn=max(maxn,ans[i]);
	}
	return sum1>2*maxn;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<3) cout<<0;
	else if (n==3){
		if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
	}
	else{
		for (int i=7;i<=pow(2,n)-1;i++){
			memset(ans,0,sizeof(ans));
			memset(two,0,sizeof(two));
			int t=i,cn=0,cn1=0,sum1=0;
			while(t){
				two[++cn]=t%2;
				sum1+=t%2;
				t/=2;
			}
			if (sum1<3) continue;
			for (int i=1;i<=n;i++) if (two[i]==1) ans[++cn1]=a[i];
			if (pd(sum1)) sum++;
		}
		cout<<sum;
	}
	return 0;
	//1
}
