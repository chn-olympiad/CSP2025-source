#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[5005],f,maxn;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f=f+a[i];
		maxn=max(maxn,a[i]);
	}
	if(f>maxn*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
