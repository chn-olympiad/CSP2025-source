#include<iostream>
using namespace std;
int a[1000000];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,n=0;
	cin>>s; 
	if(s<10){
		cout<<s;
	}
	if(s<100){
		a[1]=s%10;
		a[2]=s/10%10;
		if(a[1]>=a[2]){
			cout<<a[1]<<a[2];
		}else{
			cout<<a[2]<<a[1];
		}
	}
	if(s>100){
		for (int i=1;i<=100000;i++){
		if (s!=0){
			n++;
		}
		a[i]=s%10;
		s=s/10;
		}
		for (int i=1;i<=n;i++){
		cout<<a[i];
		}
	}
	return 0;
}
