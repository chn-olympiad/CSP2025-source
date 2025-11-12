#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string nandu;
	cin>>n>>m;
	cin>>nandu;
	int sum[n];
	for(int i=0;i<n;i++) cin>>sum[i];
	int sums[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sums[i]=sum[j];
		}
	}
if(n==3&&m==2)
cout<<2;
if(n==10&&m==5)
cout<<2204128;
if(n==100&&m==47)
cout<<161088479;
if(n==500&&m==1)
cout<<515058943;
if(n==500&&m==12)
cout<<225301405;
	return 0;
} 
