#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+6];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>=2 && m>=2){
			cout<<2;
			return 0;
		}
	}
	cout<<1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
