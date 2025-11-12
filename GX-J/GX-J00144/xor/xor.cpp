#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
bool ap=1,as=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]!=1) ap=0;
		if(a[i]>1) as=0;
	}
	if(ap==1 && k==0){
		cout << n;
		return 0;
	}
	return 0;
}
