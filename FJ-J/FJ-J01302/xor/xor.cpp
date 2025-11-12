#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],k,maxx=0,l[22300][22300],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=i;j<=n;j++){
			if(j!=i)x=x^a[j];
			if(x==k)l[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(l[i][j]==1){
				i=j+1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
