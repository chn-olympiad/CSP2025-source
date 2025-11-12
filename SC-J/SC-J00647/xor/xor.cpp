#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,k;
int f(int l,int r){
	int t=a[l];
	for(int i=l+1;i<=r;i++){
		t^=a[i];
	}
	return t;
}
int res;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=1,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=0;
		}
		if(a[i]>1){
			B=0; 
		}
	}
	if(n!=2||k!=0)A=0;
	if(A==1){
		cout<<1;
		return 0;
	}
	if(B==1){
		int one=0,zero=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				one++;
			}else{
				zero++;
			}
		}
		if(k==1)cout<<one;
		else if(k==0){
			int doubleone=0;
			for(int i=2;i<=n;i++){
				if(a[i-1]==a[i]==1){
					doubleone++;
				}
			}
			cout<<doubleone+zero;
			return 0;
		}
		return 0;
	};
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)==k)res++;
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}