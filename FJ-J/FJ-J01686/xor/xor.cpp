#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ss=1;
	for(int i=1;i<=n;i+=ss){	
		long long d=0;
		ss=1;
		for(int j=i;j<=n;j++){
			if(a[j]%2==d%2){
				d=max(d-a[j],a[j]-d);
			}else{
				d+=a[j];
			}
			if(d==k){
				sum++;
				ss=j-i+1;
				break;
			}	
		}
	}
	cout<<sum;
	return 0;
} 

