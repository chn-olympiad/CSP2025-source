#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,b,a[10086];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>n>>k; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k)sum++;
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			for(int i=0;i<=r-l+1;i++){
				if(a[i]==k)break;
				b^=a[i];
			}
			if(b==k)sum++;
			b=0;
		}
	}
	cout<<sum;
	return 0;
} 

