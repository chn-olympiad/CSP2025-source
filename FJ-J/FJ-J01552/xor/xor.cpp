#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b=0,x=0,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>a[i];
		if(a[i]==1) b++;
		if(a[i]==0) x++;
		l+=a[i];
	}
	if(b==n&&k==0){
		cout<<n;
		return 0;
	}
	if(k==1){
		cout<<x+(n-(n%2))/2;
		return 0;
	}
	cout<<l%2;
	return 0;
}
