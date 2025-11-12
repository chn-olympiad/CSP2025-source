#include<bits/stdc++.h>
using namespace std;

const int N=1e5*5+10;
long long n,ans,k,j=1,sum;
long long a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=j;i<=n+2;i++){
		sum=0; 
		for(j=i+1,sum=a[i];j<=n;j++){
			if(j==n+2){
				j=i+1;
				sum=a[i];
				if(sum==k){
					ans++;
					break;
				}else if(j>=n){
					cout<<ans;
					return 0;
				}
				continue;
			}
			sum=(sum^a[j]);
			if(sum==k){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
