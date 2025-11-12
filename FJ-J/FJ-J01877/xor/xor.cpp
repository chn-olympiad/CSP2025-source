#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int c=0;
		int d=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				c++;
			}
			if(a[i]==0){
				d=d+1+(c/2);
				c=0;
			}
		}
		d+=c/2;
		cout<<d;
		return 0;
	}
	if(k==1){
		int c=0;
		int d=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				c++;
			}
			if(a[i]==1){
				d=d+1+(c/2);
				c=0;
			}
		}
		d+=c/2;
		cout<<d;
		return 0;
	}
	cout<<0;
	return 0;
} 
