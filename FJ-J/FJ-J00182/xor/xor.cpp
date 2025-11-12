#include<bits/stdc++.h>

using namespace std;

#define int long long

int sum[500005];

signed main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k;
	cin>>n>>k;
	//n=50000;k=1145;
	
	for(int i=1;i<=n;i++){
		int a;
		//scanf("%lld",&a);
		cin>>a;
		//a=rand();
		sum[i]=sum[i-1]^a;
	}
	
	int lst=1,ct=0;
	
	for(int j=1;j<=n;j++){
		int a=sum[j]^k;
		for(int i=lst;i<=j;i++){
			if(sum[i-1]==a){
				//cout<<j<<"~"<<i<<endl;
				lst=j+1;
				ct++;
				break;
			}
		}
	}
	
	cout<<ct;

	fclose(stdin);
	fclose(stdout);

	return 0;
}

