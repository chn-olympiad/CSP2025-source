#include<bits/stdc++.h>
using namespace std;
int a[5000];
int n,ans;
void aaa(int q,int ma,int sum){
	if (q==n) {
		if (sum>ma*2) ans++;
		return;
	}
	ans%=998244353;
	aaa(q+1,ma,sum);
	ans%=998244353;
	aaa(q+1,max(ma,a[q]),sum+a[q]);
	ans%=998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if (n<3){
		cout<<0;return 0;
	}
	if (n==3){
		int ma=0,sum=0;
		sum=a[0]+a[1]+a[2];
		ma=max(a[0],max(a[1],a[2]));
		if (ma*2>=sum) cout<<0;
		else cout<<1;
		return 0;
	}
		aaa(0,0,0);
		cout<<ans;
	return 0;
}
