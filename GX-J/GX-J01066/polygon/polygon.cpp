#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,ans,m;
int a[5001],t[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m=max(m,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t[i]+=a[i];
	}
	for(int i=1;i<=n-3;i++){
		if(t[n]-t[i]<=m*2) break;
		for(int j=1;j<=n-i;j++){
			int p=t[n];
			for(int k=j;k<=i+j;k++){
				p-=a[k];
			}
		if(p>m*2) ans++;
		else break;
		}
	}
	cout<<ans;
	return 0;
}

