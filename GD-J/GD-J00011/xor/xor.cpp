#include<bits/stdc++.h>
using namespace std;
int a[1000006],b[1000006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			b[j]=a[i];
			j++;
		}
	}
	if(k==1){
		cout<<j-1;
	}
	else{
		cout<<(j-1)/2;
	}
}

