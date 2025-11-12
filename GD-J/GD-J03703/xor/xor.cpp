#include "bits/stdc++.h"
#define ll long long
using namespace std;	
ll n,k,a[1100000],i,tem,j,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	for(i=1;i<=n;i++){
		tem=a[i];
		if(tem = k){
			sum++;
			i++;
			continue;
		}
		tem=a[i];
		for(j=i+1;j<=n;j++){
			int t = tem^a[j];
			tem = tem^a[j];
			if(tem = k){
				sum++;
				i=j;
				break;
			}	
			tem = t;
		} 
	}
	cout << sum;
	return 0;
}
