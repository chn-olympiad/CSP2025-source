#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	feropen("xor.in","r",stdin);
	feropen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)sum++; 
	}
	if(k==1)cout<<sum;
	else{
		int cnt=n-sum;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				cnt++;
				a[i]=0;
				a[i+1]=0;
			}
		}
		cout<<cnt;
	}
	return 0;
}
