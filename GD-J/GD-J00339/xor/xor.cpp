#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],d[500005];//d[i]代表从第i个到当前的异或和 
long long sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int bk=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i] = a[i];
		if(a[i] == k){
			bk = i + 1;
			sum++;
			continue;
		}
		for(int j=bk;j<i;j++){
			d[j] = (d[j] ^ a[i]);
			if(d[j] == k){
				bk = i + 1;
				sum++;
				continue;
			}
		} 
	}
	cout<<sum;
	
	return 0;
} 
