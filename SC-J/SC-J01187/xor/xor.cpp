#include<bits/stdc++.h>
using namespace std;
int a[500005],b1,b2,c,b[500005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int w=0;w<=n;w++){
		for(int l=0;l<n-w;l++){
			c=0;
			b1=0;
			int r=l+w;
			for(int i=l;i<=r;i++){
				b1=b1^a[i];
				if(b[i]!=0){
					c=1;
				}
			}
			if(b1==k&&c!=1){
				b2++;
				for(int i=l;i<=r;i++){
					b[i]=1;
				}
			}
		}
	}
	cout<<b2;
	return 0;
} 