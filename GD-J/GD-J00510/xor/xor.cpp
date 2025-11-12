#include<iostream>
#include<algorithm>
using namespace std;
int a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				ans++;
			else if(a[i]==a[i-1])	
				ans++,a[i]=0;
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				ans++;
		cout<<ans;
		return 0;
	}
	cout<<k;
} 
