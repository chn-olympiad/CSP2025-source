#include<bits/stdc++.h>
using namespace std;
int n,k,a[500500],s[500500];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int maxn=0,z=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(maxn<s[j]){
				maxn=s[j];
				z=j;
			}
		}
		maxn=0;
		a[i]=s[z];
		s[z]=0;
	}
	
	return 0;
}
