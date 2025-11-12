#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==r){r=i;break;}
	}
	int a=(r+n-1)/n,b=r%n;
	if(b==0) b=n;
	if(a%2==0) b=n-b+1;
	cout<<a<<' '<<b; 
	return 0;
}
