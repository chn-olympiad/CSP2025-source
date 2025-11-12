#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=0,r=2,size=0;
	while(l<n-2&&r<n){
		int sum=0,max=0;
		for(int i=l;i<=r;i++){
			sum=sum+a[i];
			if(a[max]<a[i]){
				max=i;
			}
		}
		if(a[max]*2<sum){
			size++;
		}
		if(r==n-1){
			l++;
			r=l+2;
		}
		else{
			r++;
		}
	}
	if(size%2!=0){
		cout<<size*2-1;
	}
	else{
		cout<<size*2;
	}
	return 0;
} 
