#include<bits/stdc++.h>
using namespace std;
int a[100005],n,b[100005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	for(int k=3;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(a[i]*2<b[i]-b[i-k])ans++;
		}
	}cout<<ans;
	return 0;
}
