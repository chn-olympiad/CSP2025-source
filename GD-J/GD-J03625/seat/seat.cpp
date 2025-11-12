#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}
const int N=20;
int a[151];
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+sum,cmp);
/*
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
*/
	int i=1,j=1,cnt=1;
	while(cnt<=sum){
		if(a[cnt]==a1){
			cout<<j<<" "<<i;
			return 0; 
		}
		if(j%2==1){
			if(i<n) i++;
			else if(i==n) j++;
		}
		else{
			if(i>1) i--;
			else if(i==1) j++;
		}
		cnt++;
	}
	return 0;
}
