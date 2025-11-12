#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],num=0,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(num>maxn*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
} 
