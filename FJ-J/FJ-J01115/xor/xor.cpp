#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1&&a[i]!=0){
			f=0;
		}else if (a[i]==0){
			f=2;
		}
	}
	if (f==1)cout<<n/2;
	else if (f==2){
		int x=0,y=0;
		for (int i=1;i<=n;i++){
			if (a[i]==0)x++;
			else if (a[i]==1)y++;
		}
		if (k==0)cout<<x+y/2;
		else if (k==1)cout<<y;
	}else if (f==0){
		long long ans=0;
		for (int i=1;i<=n;i++){
			b[i]=b[i-1]^a[i];
		}
		for (int i=1;i<=n;i++){
			if (b[i]==k&&f==0){
				f=1;
				ans++;	
			}else if (b[i]==0){
				f=0;
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
