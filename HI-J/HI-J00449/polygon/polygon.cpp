#include <bits/stdc++.h>
using namespace std;
int a[10005],pre[10005];
long long c=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
	}else{
	pre[1]=a[1]; 
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=0;i<=n;i++){
		for(int j=3;j<=n;j++){
			if(pre[j]-pre[i]>a[j]) c++;
		}
	}
	cout<<c%998244353;
	}
	return 0;
} 
