#include <bits/stdc++.h>
using namespace std;
int n,x,a[50005],sum;
bool k[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>x;
	for(int i = 1;i <= n;i++) cin >>a[i];
	for(int i = 1;i <= n;i++){
		if(a[i] == x){
			sum++;
			k[i] = 1;
		}	
	}
	for(int i = 1;i <= n;i++){
		int p = a[i];
		for(int j = i + 1;j <= n&&!k[j];j++){
			p ^= a[j];
			if(p == x){
				k[j] = 1;
				sum++;
				break;
			}
		}
	}
	cout <<sum;
} 
