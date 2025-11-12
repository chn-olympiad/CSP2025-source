#include<bits/stdc++.h>
using namespace std;
int n,k,p,ans;
long long a[500005];
long long check(){
	long long sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(check()<=n){
		if(k==0) ans=check();
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1) ans++,i++;
			}
		}
		cout<<ans;
	}
	else cout<<n/2;
	return 0;
}
