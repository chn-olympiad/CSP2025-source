#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n,k,a[1000000],b;
bool f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			f=0;
		}
	}
	if(f==1){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
					
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	if(f==1){
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
					
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

*/
