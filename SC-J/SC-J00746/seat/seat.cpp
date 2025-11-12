#include<iostream>
#include<algorithm>
using namespace std;
int a[101];
int main()
{
 	int c,r,bj=0,x=0,y=0,j=0;
	cin>>c>>r;
	for(int i=1;i<=c*r;i++){
		cin>>a[i];
	}
	int d=a[1];
	sort(a+1,a+c*r+1);
	for(int i=c*r;i>=1;i--){
		bj++;
		if(a[i]==d){
			break;
		} 
	}
	if(bj%(2*c)<=c){
		cout<<bj/(c+1)+1<<" "<<bj%(2*c);
	}
	if(bj%(2*c)>c){
		cout<<bj/c+2<<" "<<2*c-bj%(2*c)+1;
	}
	return 0;
}