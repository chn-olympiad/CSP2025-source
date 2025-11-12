#include <bits/stdc++.h>
using namespace std;
int n,k,arr[5000000],num,l=-1;
bool A=1,B=1;
int fun(int a,int b){
	int t=0,k=1;
	while(a>0||b>0){
		if(a%2!=b%2)
		t+=k;
		k*=2;
		a/=2;
		b/=2;
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=1)
		A=0;
		if(arr[i]>1)
		B=0;
	}
	if(A){
		cout<<int(n/2);
		return 0;
	}
	if(B){
		if(k==0){
			for(int i=0;i<n;i++){
				if(arr[i]==0)
				num++;
				else if(arr[i+1]==1){
					num++;
					i++;
				}
			}
		}else{
			for(int i=0;i<n;i++){
				if(arr[i]==1)
				num++;
			}
		}
		cout<<num;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(arr[i]==k){
			num++;
			l=i;
			continue;
		}
		for(int j=i-1;j>l;j--){
			int b=fun(arr[i],arr[j]);
			if(b==k){
				num++;
				l=i;
				break;
			}else{
				arr[j]=b;
			}
		}
	}
	cout<<num;
	return 0;
}

