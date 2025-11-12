#include<bits/stdc++.h>
using namespace std;
int n=0,a[5001]={0};
long long num=0,sum=0;
// 998244353
long long add(int l,int r){
	int s=0;
	for(int i=l;i<=r;i++){
		s+=a[i];
	}
	return s;
}
long long cheng(int x,int y){
	long long s=1;
	for(int i=y;i>0;i--){
		s*=i;
	}
	for(int i=1;i<=x;i++){
		s/=i;
//		s%=998244353;
	}
	return s;
} 
int main(){
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
//	for(int i=0;i<n;i++){
//		cout<<a[i];
//	}
	for(int i=3;i<=n-1;i++){
		cout<<i<<':'<<'\n';
		for(int j=n;j>=0;j--){
			for(int k=0;k<j-i+1;k++){
				if(add(k,k+i-1)>2*j){
					cout<<a[k]<<' '<<a[k+i]<<'}'<<a[j]<<'\n'; 
					num+=cheng(i,j-k);
					num%=998244353;
				}
			}
		}
	}
	cout<<num;
	return 0;
//cout<<cheng(2,5);
}
/*
5
1 2 3 4 5
*/
