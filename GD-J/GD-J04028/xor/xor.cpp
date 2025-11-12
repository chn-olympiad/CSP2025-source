#include <bits/stdc++.h>
using namespace std;
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
int a[100010];
int main(){
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int num=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				num++;
			}
		}
		cout<<num;
		return 0;
	}
	return 0;
} 
