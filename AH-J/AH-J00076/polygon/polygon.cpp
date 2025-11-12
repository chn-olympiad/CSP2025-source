#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	int n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=2;j<=n;j++){
			if(a[j]>a[j-1]){
				int g;
				g=a[j];
				a[j]=a[j-1];
				a[j-1]=g;
			}
		}
	}
	if(a[1]+a[2]+a[3]>2*a[1])cout<<1;
	else cout<<0;
	return 0;
}
