#include <bits/stdc++.h>
using namespace std;
int n=0,a[5010];int d=0,s=0;
void as(int g,int x){
    for(int j=g;j<=n;j++){
		if(g>=3&&x>a[j])s++;
		if(g<n) as(j+1,x+a[j]);
		}
	return;
	}
int main(){   
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	as(1,0);
	cout<<s%998244353;
	return 0;
}
