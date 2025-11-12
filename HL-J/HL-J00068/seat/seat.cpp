#include<bits/stdc++.h>
using namespace std;
int a[101];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int f=a[1];
	int j;
	sort(a+1,a+s+1,greater<int>());
	for(int i=1;i<=s;i++){
		if(a[i]==f){
			j=i;
			break;	
		} 
	}
	//cout<<j<<endl;
	int c,r;
	if(j%n==0) c=j/n;
	else c=j/n+1;
	if(c%2==1){
		if(j%n==0) r=n;
		else r=j%n;
	}
	else if(c%2==0){
		if(j%n==0) r=1;
		else r=(n-(j%n)+1);
	}
	cout<<c<<' '<<r;
	return 0;
}