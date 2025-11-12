#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,ans;
	const int N=1e6+10;
	int a[N],sum=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=k-1;i++){
		ans^=a[i];
		if (ans==k){
			sum++;
			break;
		}
	}
	for (int i=k;i<=n;i++){
		ans^=a[i];
		if (ans==k){
			sum++;
			break;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}