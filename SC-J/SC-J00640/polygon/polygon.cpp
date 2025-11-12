#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],ans=-1,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans=max(a[i],ans);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int num=a[i]+a[j];
				if(num+a[k]>=2*ans){
					cnt++;
				}
			}
		}
	}
	cnt%=998;
	cnt%=244;
	cnt%=353;
	cout<<cnt;
	return 0;
}