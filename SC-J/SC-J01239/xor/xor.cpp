#include<bits/stdc++.h>
using namespace std;
int n,t,k=0,a[5050];
long long cnt=0;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(k<=n){
		ans=0;
		for(int i=1;i<=n-k;i++){
			ans=a[i];
			for(int j=i;j<=i+k;j++){
				ans=ans^a[j];
			}
			if(ans==t){
				cnt++;
			}
		}
		k++;
	}
	cout<<cnt;
	return 0;
}