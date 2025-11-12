#include<iostream>
using namespace std;
int main(){
	//freopen("seat.in","r","stdin");
	//freopen("seat.out","w","stdout");
	int n,m;
	cin>>n>>m;
	int x=n*m;
	int a[x];
	int b=0;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	int c=0,r=0;
	cout<<n<<" "<<m;
//	int R=a[0];
//	for(int j=0;j<x;j++){
//		for(int i=0;i<x-1;i++){
//			if(a[i]<a[i+1]){
//				m=a[i];
//				a[i]=a[i+1];
//				a[i+1]=m;
//			}
//		}
//	}
//	for(int i=0;i<x;i++){
//		if(a[i]==R){
//			b=i+1;
//		}
//	}
////	cout<<b;
//int num=0;
//	for(int i=n;i<=x;i=i*2){
//		c++;
//		if(b<=i){
//			num=b-i+1;
//			int ans=i;
////			cout<<b<<" "<<i;
//			break;
//		}
//	}
////	cout<<b<<endl;
//	if(c%2==0){
//		r=ans+num;
//	}else{
//		r=;
//	}
//	cout<<c<<" "<<r;
	return 0;
}
