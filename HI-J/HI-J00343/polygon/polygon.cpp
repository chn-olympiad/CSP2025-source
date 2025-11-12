#include<bits/stdc++.h>
using namespace std;
int n,ans=0,u=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	u=max(a[1],a[2]);
	int v=max(u,a[3]);
	for(int i=1;i<=n;i++){
		if(m>3&&(a[j]+a[j+1]+a[j+2])>v){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

