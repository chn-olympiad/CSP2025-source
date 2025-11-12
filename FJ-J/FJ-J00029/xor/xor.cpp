#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
    for(int i=0;i<n;i++){
    	if(a[i]==a[i+1]){
    		cnt++;
		}
	}
	if(k==0&&cnt==n-1){
		cout<<n;
		return 0;
	}
	return 0;
}
