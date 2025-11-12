#include<bits/stdc++.h>
using namespace std;
long long n,k,s[500005],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if (s[i]==k){
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if (s[i]+s[j]==k&&s[i]!=s[j]){
				sum+=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
