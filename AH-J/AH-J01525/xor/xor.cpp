#include<bits/stdc++.h>
using namespace std;
const int N=5e+5;
int a[N+1],n,k,sum,c;
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=0;
			if(i==j) num=a[i]|a[j];
			else{
				for(int k=i;k<j;k++){
					c=a[k]|a[k+1];
					num+=c;
				}
			}
			if(num==k){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;

}
