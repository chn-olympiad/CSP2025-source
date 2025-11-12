#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int sum=0;
	bool x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)sum++;
		if(a[i]!=1)x=1;
	}
	if(x==0){
		cout<<0;
	}else{
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
