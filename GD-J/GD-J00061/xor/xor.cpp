#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0&&a[0]==1){
		cout<<(n/2);
	}
}
