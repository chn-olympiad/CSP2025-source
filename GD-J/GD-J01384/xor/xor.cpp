#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[100005];
long long sum1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		int r=s[i];
		int sum=0;
		for(int j=i;j<=n;j++){
			if(i==j&&s[i]==m){
				sum++;
				j++;
				r=s[j];
			}
			else if((r^s[j])==m){
				j++;
				r=s[j];
				sum++;
			}
			else if(i+1==j){
				r=(r^s[j]);
			}
		}
		if(sum>sum1){
			sum1=sum;
		}
	}
	cout<<sum1;
	return 0;
}
