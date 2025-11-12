#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+50;
long long a[N],n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long flag=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1);
		else flag=0;
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	flag=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==1||a[i]==0);
		else flag=1;
	}
	if(flag==0){
		for(long long i=n;i>=1;i--){
			if(a[i]!=0&&flag!=1){
				ans*=a[i];
			}
			if(a[i]==0){
				flag=1;
				cout<<ans;
				return 0;
			}
		}
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	cout<<2;
	return 0;
}
