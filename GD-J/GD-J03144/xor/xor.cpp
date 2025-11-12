#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,b,l=0,r=1,ans;
	char a[100000],c[100000];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>b;
		while(b!=0){
			a[i]+=b%2;
			b=b/2;
		}
	if(i>0){           
		for(int j=a[i].size();j>=0;i--){
			if(a[i].j==a[i-1].j){
				c[i]=c[i]+'0';
			}
			else{
				c[i]=c[i]+'1';
			}
		} 
	} 
	}
for(int i=)
	return 0;
}