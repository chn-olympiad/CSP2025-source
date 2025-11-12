#include<bits/stdc++.h>
using namespace std;
int n,a[11451],zong,b[114514];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i-1]+a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-2;i++){
		for(int j=i;j<=n-1;j++){
			int zuida=2*a[i];
			int zhi=1;
			for(int k=j;k<=n;k++){
				int he=a[i]+a[j]+a[k];
				if(he<=zuida&&k!=j){
					int T=n-k+1;
					while(T--){
						zhi*=2;
					}
					T=k-j-1;
					while(T--){
						zhi*=3;
					}
					zong+=zhi;
					break;
				}
			}
		}
	}
	cout<<zong;
	return 0;
}
