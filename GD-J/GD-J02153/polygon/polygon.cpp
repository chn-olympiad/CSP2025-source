#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int v=1;v<j;v++){
				if(max(a[i],max(a[j],a[v]))*2<a[i]+a[v]+a[j])ans++;
			}
		}
	}
	cout<<ans;
}
