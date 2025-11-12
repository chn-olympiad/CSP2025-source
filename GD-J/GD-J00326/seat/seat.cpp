#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int num=1;
	int a=0;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		int p;
		cin>>p;
		if(p>a)num++;
	}
	int c=(num-1)/n+1;
	cout<<c<<" ";
	if(c%2==1)cout<<(num-1)%n+1;
	if(c%2==0)cout<<n+1-((num-1)%n+1);
	return 0;
} 
