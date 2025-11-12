#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool b=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			b=1;
		}
	}
	if(b==0&&k==0){
		cout<<0;
		return 0;
	}
	int sum1=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int p=i;p<=j;p++){
				sum=sum|a[p];
			}
			if(sum==k){
				sum1++;
				i=j;
				break;
			}
		}
	}
	cout<<sum1;
}
