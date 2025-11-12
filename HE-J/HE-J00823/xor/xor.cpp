#include<bits/stdc++.h>
using namespace std;
long long n,k,a[50010],s[50010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
	}else{
		int i=1,j=1;
		while(j<=n){
			for(int b=i;b<=j;b++)if((s[j]^s[b-1])==k){
				i=j,ans++;
				break;
			}
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
