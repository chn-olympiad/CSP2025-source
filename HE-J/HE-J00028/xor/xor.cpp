#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin >> n >> k;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==k){
			sum++;
		}
	}
	int num=a[0];
	for(int i=0;i<n;i++){
		if(a[i]!=num){
			cout << sum;
			fclose(stdin);
			fclose(stdout);
			return 0;	
		}
	}
	cout << n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
