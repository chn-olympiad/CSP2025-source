#include<bits/stdc++.h>
using namespace std;
long long a[500005],cnt=0,s[500005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>ans;j--){
			if((s[i]^s[j-1])==k){
				cnt++;
				ans=i;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
