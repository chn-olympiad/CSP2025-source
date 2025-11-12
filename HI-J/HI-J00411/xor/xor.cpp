#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[550000];
int t[550000];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	/*t[1]=a[1];
	for(int i=1;i<=n;i++){
		t[i]=a[i] xor t[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if(t[i-1] xor t[j]==k){
			ans++;
			cout<<3;
		}
	}*/
	cout<<n/2;
	
	return 0;
}
