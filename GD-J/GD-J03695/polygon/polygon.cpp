#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000];
long long ans=0;
int main(){
	freopen("polygon in","r",stdin);
	freopen("polygon out","w",stdout);
	for(int i,i<n,i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(intj=1,j<=n,j++){
		if(j<i)cnt[i][j];
	}else cnt[i][j];
	for(int i=3;i<=n;i++){
		for(int j=3;j<=n;j++){
			if(cnt[i][j]<a,[j]*2)continue;
		}
	}
}
