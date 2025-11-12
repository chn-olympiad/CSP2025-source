#include<bits/stdc++.h> 
using namespace std;
int n,k,cnt=0,ctt=0;
int a[1010000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=ctt+1;i<=n;i++){
		for(int j=n;j>=i;j--){
			ctt=j;
			if(k==a[i]-a[j-i]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
