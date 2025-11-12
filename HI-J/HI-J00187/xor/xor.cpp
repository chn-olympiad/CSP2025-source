#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],cnt;
int xr(int i,int j){
	int ans=a[i];
	for(int l=i+1;l<j;l++){
		ans=a[l] xor ans;
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]==k&&i==j){
				cnt++;
				continue;
			}
			if(xr(i,j)==k){
				cnt++;
				cout << ' ' << i << ' ' << j << endl;
				continue;
			}
			cout << i << ' ' << j <<endl;
		}
	}
	cout << cnt-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
