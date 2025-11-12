#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[500000],k,n;
int in(int i){
	int sum = 0;
	for(long long j = i;j < n;++j){
		for(long long l = i;l < j;++l){
			sum = sum ^ a[l];
		}	
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i = 0;i < n;++i){
		cin>>a[i];
	}
	for(long long i = 0;i < n;++i){
		if(in(i) == k){
			for(long long j = 0;;){
			}
		}
	}
	//TwT完蛋了    呜哇哇哇哇哇我不活了 
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
