#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,a[99999];
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	cin>>n;
	int s=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s=s+a[i];
	}
	sort(a,a+n,cmp);
	if(n<=3){
		cout<<1;
	}
	
	return 0;
}