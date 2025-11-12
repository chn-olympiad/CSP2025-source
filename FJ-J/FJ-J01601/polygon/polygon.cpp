#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n; 
	int i,j;
	bool f=1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=false;
	}
	sort(a+1,a+n+1);
	if(f==true){
		int e=pow(2,n-2);
		cout<<(e-1)%998244353;
		return 0;
	}
	int l=1,r=3;
	while(r<=n){
		int sum=0,ma=-1;
		for(j=l;j<=r;i++){
			sum+=a[j];
			ma=max(ma,a[j]);
		}
		if(sum>ma*2) ans++;
		r++;
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
