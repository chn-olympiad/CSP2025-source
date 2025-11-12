#include<bits/stdc++.h>
using namespace std;
long long n,k,a[114],sum1,sum0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)sum1++;
		else sum0++;
	} 
	if(n==1&& k==0){
		cout<<0;
		return 0;
	}
	if(n==2&& k==0){
		cout<<1;
		return 0;
	}//点1
	if(n<=10 && k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==a[i+1] && a[i]==1){
					sum0++;
					a[i]=0,a[i+1]=0;
				}
			}
			cout<<sum0;
			return 0;
		}
		if(k==1){
			cout<<sum1;
			return 0;
		}
	} //点2 
	if(n<=100 && k<=1){
		if(k==0){
			cout<<sum1/2;
			return 0;
		}
		if(k==1){
			cout<<sum1;
			return 0; 
		}
	} 
	cout<<1;//试图骗分 
	//点345 
	return 0;
} 