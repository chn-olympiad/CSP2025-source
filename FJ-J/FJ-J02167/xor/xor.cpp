#include<bits/stdc++.h>
using namespace std;
int a[100011];

int main(){
	//preoper("xor.in","r",stdin);
	//preoper("xor.out","w",stdout);
	int n,k,m=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			m++;
		}
	}
	cout<<m+1;
	return 0;
}
