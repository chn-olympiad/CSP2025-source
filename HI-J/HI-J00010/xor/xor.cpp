#include<bits/stdc++.h>
using namespace std;
int a[100010],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
   	for(int i=1;i<=n;i++){
   		if(a[i]==k)s++;
	}
	cout<<s;
	return 0;
}
