#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	int n,s=0,k;
	cin>>n>>k;
	int a[100000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i++){
		for(int j=1;j<=i;j++){
			int l=0;
			for(int q=j;q<=i;q++){
				l+=a[q];
			}
			if(l==k){
				s++;
			}
				
		}
	}
	cout<<s;
	return 0;
}
