#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],tot,ans,m,maxn;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=0;m=0;maxn=0;
		for(int j=1;j<=i;j++){
			ans+=a[j];
			m=i-j+1;
			maxn=max(a[j],maxn);
			if(m>=3&& ans>=maxn){
				tot++;
			}
		}
	}
	cout<<tot;
	
	return 0;
}
