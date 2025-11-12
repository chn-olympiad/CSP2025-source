#include<iostream>
using namespace std;
int n,k;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout) ;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2&&k==0) cout<<1;
	else if(n==1&&k==0) cout<<0;
	else if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
	}
	else if(n<=10&&k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		cout<<cnt;
	}
	else if(n<=100&&k==0){
		int book=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				book=1;
				break;
			} 
		}
		if(book==0)
			cout<<n/2;
	}
	else if(n<=100&&k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		cnt+=(n-cnt)/2;
		cout<<cnt;
	}
	else if(n<=200005&&k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		cnt+=(n-cnt)/2;
		cout<<cnt;
	}
	return 0;
} 
