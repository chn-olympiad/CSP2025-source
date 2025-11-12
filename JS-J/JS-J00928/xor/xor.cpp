#include<bits/stdc++.h>
using namespace std;
long long  a[500005]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long last=1,sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=last;j--){
			long long num=0;
			for(int l=i;l>=j;l--){
				num=num^a[l];
			}
			if(num==k){
				sum++;
				last=i+1;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
