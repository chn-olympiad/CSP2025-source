#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,aXor[500005];
int chooseAFanwei(int l,int r,int step){
	int noPublicSum=1;
	for(int i=1;i<l;i++){
		aXor[i]=(aXor[i] xor aXor[i+1]);
	}
	for(int i=r+1;i<=step;i++){
		aXor[i]=(aXor[i] xor aXor[i+1]);
	}
	for(int i=1;i<=step;i++){
		if(aXor[i]==k){
			noPublicSum+=chooseAFanwei(i+(n-step),i+(n-step)+1,step-1);
		}
	}
	return noPublicSum;
}
int x0r(int step){
	int aXor[500005]={};
	int noPublicSum=0;
	for(int i=1;i<=step;i++){
		aXor[i]=(a[i] xor a[i+1]);
		if(aXor[i]==k){
			noPublicSum+=chooseAFanwei(i+(n-step),i+(n-step)+1,step-1);
			noPublicSum=max(x0r(step),noPublicSum);
		}
	}
	
	return noPublicSum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		aXor[i]=(a[i] xor a[i+1]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s=max(chooseAFanwei(i,i,n),s);
		}
	}
	cout<<max(x0r(n),s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

