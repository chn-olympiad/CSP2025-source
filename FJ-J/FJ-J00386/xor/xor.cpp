#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,k;
bool ty=0;
int find1(){
	int num=0;
	int num1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			num1++;
		}
		else{
			num++;
			num+=(num1)/2;
			num1=0;
		}
	}
	num+=(num1)/2;
	return num;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ty=1;
	}
	if(ty==0){
		cout<<n/2;
		return 0;
	}
	else{
		if(k==0){
			cout<<find1();
			return 0;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			cout<<sum;
			return 0;
		}
	}
	return 0;
}

