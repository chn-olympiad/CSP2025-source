#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5*1e5+10;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool c=1;
	int sd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			c=0;
			sd++;
		}

	}
	int kkk=a[1],kk=0;
	for(int i=2;i<=n;i++){
		if(a[i]==k && k==0){
			kk++;
		}
		k=a[i];
	}
	if(c){
		int xy=n/2;
		cout<< xy;
	}
	else{
		if(k==0)
			cout<< sd;
		else
			cout<< n-sd+kk;
	}
	return 0;
}
