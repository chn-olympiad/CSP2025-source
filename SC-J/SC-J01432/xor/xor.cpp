#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<cstring>
using namespace std;
int a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[k];
	return 0;
} 