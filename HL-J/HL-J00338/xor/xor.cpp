#include<iostream>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<cstring>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<k;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(maxn==0){
		cout<<1;
		return 0;
	}
	cout<<maxn;
	return 0;
} 
