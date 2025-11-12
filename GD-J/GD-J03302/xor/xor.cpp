#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500006];
	int minn=1000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn) minn=a[i];
	}
	if(k==0&&minn==1){
		cout<<n/2;
	}
	else if(k<=1){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
			cout<<sum;
		}
		if(k==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) sum++;
				else if(a[i]==1&&a[i+1]==1){
					sum++;
				i+=1;
				}
			}
			cout<<sum;
		}
	}
	return 0;
}
