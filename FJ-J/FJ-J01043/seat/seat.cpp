#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[105];
	int x;
	cin>>x;
	a[0]=x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	sort(a,a+n*m,cmp);
	int s;
	for(int i=0;i<n*m;i++){
		if(x==a[i]){
			s=i;
			break;
		} 
	}
	int c=s/n+1;
	int r;
	if(c%2==0){
		r=n-s%n;	
	}else{
		r=s%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
} 
