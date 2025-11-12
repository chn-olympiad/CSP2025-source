#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int n,k;
int a[N];
bool A=true;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0) A=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) A=false;
	}
	if(A){
		cout<<n/2;
		return 0;
	}
	int lem=0,sum=0;
	for(int i=1;i<=n;i++){
		lem^=a[i];
		if(lem==k){
			lem=0;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
