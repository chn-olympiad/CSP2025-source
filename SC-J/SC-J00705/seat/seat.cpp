#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	//
	cin>>n>>m;
	cin>>a[0];
	int f=a[0];
	for(int i=1;i<n*m;i++)cin>>a[i];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
		if(a[i]==f){
			f=n*m-i;
			break;
		}
	int y=int(f*1.0/n+0.999),x;
	if(y%2==0){
		x=n-f%n+1;
		if(x>n)x%=n;
	}else{
		if(n==f)n++;
		x=f%n;
	}cout<<y<<" "<<x;
	return 0;
}