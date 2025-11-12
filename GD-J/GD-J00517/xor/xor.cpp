#include<bits/stdc++.h>
using namespace std;
long long n=0;
long long k=0;
long long a[500860];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
