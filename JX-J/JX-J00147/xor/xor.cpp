#include<bits/stdc++.h>
using namespace std;
int n,a[100000],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q1=1,q2=1,q3=1;
	for(int i=1;i<=n;i++){
		q1*=i;
		if(i<=k) q2*=i;
		if(i<=n-k) q3*=i;
	}
	cout<<q1/q2/q3;
	return 0;
}
