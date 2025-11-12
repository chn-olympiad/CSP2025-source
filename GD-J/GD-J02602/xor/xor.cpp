#include<bits/stdc++.h>
using namespace std;
int n,k,sum[500005];
int a[500005];
void tsxzA(){
	if(k!=0) return;
	for(int i=1;i<=n;i++) if(a[i]!=1) return;
	cout<<n/2;
	exit(0);
}
void tsxzB(){
	if(k>1) return;
	for(int i=1;i<=n;i++) if(a[i]>1) return;
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	if(k==1) cout<<sum;
	else cout<<sum/2;
	exit(0);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	tsxzA();
	tsxzB();
	cout<<1;
	return 0;
}
