#include<bits/stdc++.h>
using namespace std;
int a[500001],cnt;
bool o;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=a[i]|a[i+1];
			for(int k=i+1;k<j;k++){
				sum|=a[k]|a[k+1];
			}
			if(j==1){
				l=i;
				r=j;
				cnt++;
			}
			if(sum==k){
					if(j<l||j>r){
						l=i;
						r=j;
						cnt++;
					}	
			}
			sum=0;
		}
	}
	if(cnt%2==0){
		cout<<cnt/2;
	}else{
		cout<<cnt;
	}
	
} 
