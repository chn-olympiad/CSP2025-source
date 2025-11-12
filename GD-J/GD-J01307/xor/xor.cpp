#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	} 
	int sum=0;
	for(int i = 0;i < n;){
		int t=a[i],j=i+1,c=1;
		while(t!=k&&j<n){
			t=t^a[j];
			j++;
			c++;
		}
		if(t!=k){
			c=0;
			i++;
		} else {
			sum++;
			i+=c; 
		}
	}
	cout << sum;
} 
