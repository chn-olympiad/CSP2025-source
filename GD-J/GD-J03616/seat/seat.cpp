#include<bits/stdc++.h>
using namespace std;
int n,m,point[1010];
int main(){
	cin>>n>>m>>point[1];
	int point_1=point[1];
	for(int i=2;i<=n*m;i++){
		cin>>point[i];
	}sort(point+1,point+n*m+1);
	int k=0;
	while(point_1!=point[k]){
		k++;
	}
	k=n*m-k+1;
	int c=k/n+1,gh=(k%n+n-1)%n+1;
	if(k%n==0){
		c--;
	}cout<<c<<' ';
	if(c%2==0){
		cout<<n-gh+1;
	}
	else{
		cout<<gh;
	}
	return 0;
}
