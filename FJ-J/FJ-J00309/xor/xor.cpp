#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long ans=0;
	long long a[500005]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}if(k==0){
		cout<<n;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1)){
				ans++;
				i++;
			}
		}cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
