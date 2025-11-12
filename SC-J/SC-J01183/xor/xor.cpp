#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a[500050]={0};
long long s[500050]={0};
long long ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	long long n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	
	int t=1;
	while(t<=n){
		int t0=t;
		for(int i=t;i<=n;i++){
			if(((a[i]^k)==0)||(((s[i]^s[t-1])^k)==0)){
				ans++;
				t=i+1;
				break;
			}
		}
		if(t==t0){
			t++;
		}
	}
	
	cout<<ans;
	


	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
