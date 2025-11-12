#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m],sum=1,o=1,nm=n*m;
	cin>>a[0];
	for(int i=1;i<nm;i++){
		cin>>a[i];
		if(a[i]>a[0]) sum++;
	}
	while(sum>m){
		o++;
		sum-=m;
	}
	cout<<o<<" ";
	if(o%2==1)
	cout<<sum;
	else
	cout<<n-sum+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
