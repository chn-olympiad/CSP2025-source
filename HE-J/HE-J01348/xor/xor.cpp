#include<bits/stdc++.h>
using namespace std;
int n,k,a[500002];
int yh(int a,int b){
	int r=0,k=1;
	while(a!=0&&b!=0){
		int a1=a&1,b1=b&1;
		if(a1!=b1) r+=k;
		a=a>>1;
		b=b>>1;
		k*=2;
	}
	return r+a*k+b*k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		int b;
		cin>>b;
		a[i]=yh(a[i-1],b);
	}
	int ans=0,sum=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(yh(a[i-1],a[j])==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
