#include<bits/stdc++.h>
std::ifstream("xor.in");
std::ofstream("xor.out");
int main(){
	int n,k,a[500001],sum=0,ans=0;
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int p=i;p<=j;p++){
				sum^=a[p];
			}
			if(sum==k){
				ans++;
			}
		}
	}
	fout<<ans;
	return 0;
}
