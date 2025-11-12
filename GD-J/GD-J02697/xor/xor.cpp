#include<bits/stdc++.h>
using namespace std;
int n,a[50005],k,sum=0;
char b[50005][25];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==1){
			if(a[i]==1)sum++;
		} 
	}
	cout<<sum;
	return 0;
} 

