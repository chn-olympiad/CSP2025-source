#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,num=0;
	long long k;
	bool b=true;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) b=false;
	}
	if(k==0 && b)
	{
		cout<<n/2;
		return 0;
	}
	else if(k==0){
		for(int i = 1;i<=n;i++){
			if(a[i]==0){
				num++;
				continue;
			}
			if(a[i]^a[i+1]==0) num++;
		}
	}
	else{
		for(int i = 1;i<=n;i++){
			if(a[i]^a[i+1]==0) num++;
		}
	}
	cout<<num;
	return 0;
} 
