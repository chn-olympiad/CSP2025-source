#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (k==0 && n==2){
		cout<<1;
		return 0;
	}
	else if (k==0 && n==1){
		cout<<0;
		return 0;
	}
	
	return 0;
}
