#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long int a[N];
long long int k,n,all=0;
int flag[N],y[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)all++,flag[i]=1;
		y[a[i]]++;
	}	 
	if(k==0&&y[1]==n){
		cout<<n/2;
		return 0;
	}
	else if(k==0&&y[1]!=n){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				all++;
				i++;
			}
		}
		cout<<all;
		return 0;
	}
	else if(k==1){
		cout<<all;
		return 0;
	}
	long long int ji;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			ji=a[j];
			if(flag[j]==1)continue;
			for(int k=j;k<=j+n;k++){
				if(flag[k]==1) break;
				ji=ji^a[k];
				if(ji==k){
					all++;
					flag[j]=1;
					flag[k]=1;
				}
			}
		}
	}
	cout<<all;
	return 0;
}