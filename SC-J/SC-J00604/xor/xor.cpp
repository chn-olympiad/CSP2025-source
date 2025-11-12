#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0,s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=t;j<=i;j++){
			if(j==i&&a[i]==k){
				t=1+i;
				j=i+1;
				ans++;
			}
			else if(j!=i&&s[i]^s[j-1]==k){
				t=i+1;
				j=i+1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}