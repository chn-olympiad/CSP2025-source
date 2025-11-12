#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i;j<=n;j++){
			sum=sum+(sum^a[j]);
			if(sum==k){
				cnt++;
				break;
			}
		}
	} 
	cout<<cnt;
	return 0;
} 
